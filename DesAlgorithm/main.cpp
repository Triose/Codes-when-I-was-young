#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
using namespace std;

#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define per(i,a,b) for(int i = (a); i >=(b); --i)
#define repe(i,a,b) for(int i = (a); i <= (b); ++i)
#define clearStr(str) (memset(str, '\0', sizeof(str)))

bitset<64> key;
bitset<48> subkey[16];


const int IP[] = { 58, 50, 42, 34, 26, 18, 10, 2,
             60, 52, 44, 36, 28, 20, 12, 4,
             62, 54, 46, 38, 30, 22, 14, 6,
             64, 56, 48, 40, 32, 24, 16, 8,
             57, 49, 41, 33, 25, 17, 9,  1,
             59, 51, 43, 35, 27, 19, 11, 3,
             61, 53, 45, 37, 29, 21, 13, 5,
             63, 55, 47, 39, 31, 23, 15, 7 };


// 密钥置换表，将64位密钥变成56位
const int PC_1[] = {57, 49, 41, 33, 25, 17, 9,
              1, 58, 50, 42, 34, 26, 18,
              10,  2, 59, 51, 43, 35, 27,
              19, 11,  3, 60, 52, 44, 36,
              63, 55, 47, 39, 31, 23, 15,
              7, 62, 54, 46, 38, 30, 22,
              14,  6, 61, 53, 45, 37, 29,
              21, 13,  5, 28, 20, 12,  4};

// 压缩置换，将56位密钥压缩成48位子密钥
const int PC_2[] = {14, 17, 11, 24,  1,  5,
              3, 28, 15,  6, 21, 10,
              23, 19, 12,  4, 26,  8,
              16,  7, 27, 20, 13,  2,
              41, 52, 31, 37, 47, 55,
              30, 40, 51, 45, 33, 48,
              44, 49, 39, 56, 34, 53,
              46, 42, 50, 36, 29, 32};

// 每轮左移的位数
const int shiftBits[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};


// 扩展置换表，将 32位 扩展至 48位
const int E[] = {32,  1,  2,  3,  4,  5,
           4,  5,  6,  7,  8,  9,
           8,  9, 10, 11, 12, 13,
           12, 13, 14, 15, 16, 17,
           16, 17, 18, 19, 20, 21,
           20, 21, 22, 23, 24, 25,
           24, 25, 26, 27, 28, 29,
           28, 29, 30, 31, 32,  1};

// S盒，每个S盒是4x16的置换表，6位 -> 4位
const int S_BOX[8][4][16] = {
        {
                {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
        },
        {
                {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
        },
        {
                {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
        },
        {
                {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
        },
        {
                {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
        },
        {
                {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
                {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
        },
        {
                {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
                {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
        },
        {
                {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
                {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
        }
};

// P置换，32位 -> 32位
const int P[] = {16,  7, 20, 21,
           29, 12, 28, 17,
           1, 15, 23, 26,
           5, 18, 31, 10,
           2,  8, 24, 14,
           32, 27,  3,  9,
           19, 13, 30,  6,
           22, 11,  4, 25 };



// 尾置换表
const int IP_1[] = {40, 8, 48, 16, 56, 24, 64, 32,
              39, 7, 47, 15, 55, 23, 63, 31,
              38, 6, 46, 14, 54, 22, 62, 30,
              37, 5, 45, 13, 53, 21, 61, 29,
              36, 4, 44, 12, 52, 20, 60, 28,
              35, 3, 43, 11, 51, 19, 59, 27,
              34, 2, 42, 10, 50, 18, 58, 26,
              33, 1, 41,  9, 49, 17, 57, 25};

bitset<64> charToBitset(const char str[8]) {
    int up = 64;
    bitset<64> ret;
    rep(i, 0, 8) {
        int tmp = str[i];
        per(j, 8, 1) {
            ret[up - (i * 8 + j)] = tmp % 2;
            tmp >>= 1;
        }
    }
    return ret;
}

char * bitsetToChar(const bitset<64> & bs) {
    int up = 64;
    char * ret = new char(8);
    rep(i, 0, 8) {
        int tmp = 0;
        repe(j, 1, 8) {
            tmp += bs[up - (i * 8 + j)];
            tmp <<= (j == 8 ? 0 : 1);
        }
        ret[i] = tmp;
    }
//    cout << ret << "\n";
    return ret;
}

bitset<28> leftShift(bitset<28> & cur, int cnt) {
    bitset<28> ret;
    rep(i, 0, 28) ret[i] = cur[(i + 28 - cnt) % 28];
    return ret;
}

void GenerateSubKey() {
    bitset<56> realkey;
//    cout << key << endl;
    rep(i, 0, 56) realkey[55 - i] = key[64 - PC_1[i]];
//    cout << realkey << "\n";
    bitset<28> former, latter;
    rep(i, 0, 28) former[27 - i] = realkey[55 - i], latter[27 - i] = realkey[27 - i];
//    cout << former << " " << latter << "\n";
    rep(rd, 0, 16) {
//        cout << "shift " << shiftBits[rd] << "\n";
        former = leftShift(former, shiftBits[rd]);
        latter = leftShift(latter, shiftBits[rd]);
//        cout << former << " " << latter << "\n";
        bitset<56> tmp;
        rep(i, 0, 28) tmp[55 - i] = former[27 - i], tmp[27 - i] = latter[27 - i];
//        cout << "tmp: \n" << tmp << "\n";
        rep(i, 0, 48) subkey[rd][47 - i] = tmp[56 - PC_2[i]];
//        cout << "subkey: \n" << subkey[rd] << "\n";
    }
}

bitset<32> F(const bitset<32> & part, bitset<48> sk) {
    bitset<32> tmp;
    bitset<48> extpart;
//    cout << part << "\n";
    rep(i, 0, 48) extpart[47 - i] = part[32 - E[i]];
//    cout << extpart << "\n";
    extpart ^= sk;
//    cout << extpart << "\n";
    rep(i, 0, 8) {
        int x, y;
        x = (extpart[47 - (i * 6)]) << 1 + extpart[47 - (i * 6 + 5)];
        y = (extpart[47 - (i * 6 + 1)] * 8) +
                (extpart[47 - (i * 6 + 2)] * 4) +
                (extpart[47 - (i * 6 + 3)] * 2) +
            extpart[47 - (i * 6 + 4)];
//        cout << "x : " << x << " y : " << y << "\n";
//        cout << extpart[47 - (i * 6)] << extpart[47 - (i * 6 + 5)] << "\n";
//        cout << extpart[47 - (i * 6 + 1)] << extpart[47 - (i * 6 + 2)] << extpart[47 - (i * 6 + 3)] << extpart[47 - (i * 6 + 4)] << "\n";
        int value = S_BOX[i][x][y];
//        cout << "value: " << value << "\n";
        per(j, 3, 0) tmp[31 - (i * 4 + j)] = value % 2, value >>= 1;
//        cout << tmp[31 - (i * 4)] << tmp[31 - (i * 4 + 1)] << tmp[31 - (i * 4 + 2)] << tmp[31 - (i * 4 + 3)] << "\n";
    }
//    cout << tmp << "\n";
    bitset<32> ret;
    rep(i, 0, 32) ret[31 - i] = tmp[32 - P[i]];
//    cout << ret << "\n";
    return ret;
}



bitset<64> encipher(bitset<64>& plain) {
    bitset<64> res;
    bitset<64> replain;
    //IP置换
//    cout << plain << "\n";
    rep(i, 0, 64) replain[63 - i] = plain[64 - IP[i]];
//    cout << replain << "\n";
    //截取左边和右边
    bitset<32> left, right;
    rep(i, 0, 32) left[31 - i] = replain[63 - i], right[31 - i] = replain[31 - i];
//    cout << left << " " << right << "\n";
    rep(i, 0, 16) {
        bitset<32> tmp = left;
        left = right;
        right = tmp ^ F(right, subkey[i]);
    }
//    cout << right << " " << left << "\n";
    rep(i, 0, 32) res[63 - i] = right[31 - i], res[31 - i] = left[31 - i];
//    cout << res << "\n";
    bitset<64> ret;
    rep(i, 0, 64) ret[63 - i] = res[64 - IP_1[i]];
    return ret;
}

bitset<64> decipher(bitset<64> & cipher) {
    bitset<64> res;
    bitset<64> recipher;
    //IP置换
    rep(i, 0, 64) recipher[63 - i] = cipher[64 - IP[i]];
    //截取左右两边
    bitset<32> left, right;
    rep(i, 0, 32) left[31 - i] = recipher[63 - i], right[31 - i] = recipher[31 - i];
    per(i, 15, 0) {
        bitset<32> tmp = left;
        left = right;
        right = tmp ^ F(right, subkey[i]);
    }
    rep(i, 0, 32) res[63 - i] = right[31 - i], res[31 - i] = left[31 - i];
    bitset<64> ret;
    rep(i, 0, 64) ret[63 - i] = res[64 - IP_1[i]];
//    cout << ret << "\n";
    return ret;
}


int main() {
    //得到密钥
    key = charToBitset("symmetri");
    //产生16个子密钥
    GenerateSubKey();
//    cout << key << "\n";
//    cout << bitsetToChar(key) << "\n";
    char instr[8]; char * outstr;
    bitset<64> plain, cipher;
    ifstream fin; fin.open("/home/triose/ClionProjects/Des/plaintext", ios::binary);
    ofstream fout; fout.open("/home/triose/ClionProjects/Des/ciphertxt", ios::binary);
    while(fin) {
        clearStr(instr);
        fin.read(instr, sizeof(instr));
//        cout << instr << "\n";
        plain = charToBitset(instr);
//        cout << bitsetToChar(plain) << "\n";
//        cout << encipher(plain) << "\n";
        outstr =  bitsetToChar(encipher(plain));
//        cout << outstr << "\n";
        fout.write(outstr, sizeof(outstr));
    }
    fin.close();
    fout.close();

    fin.open("/home/triose/ClionProjects/Des/ciphertxt", ios::binary);
    fout.open("/home/triose/ClionProjects/Des/plaintext1", ios::binary);
    while(fin) {
        clearStr(instr);
        fin.read(instr, sizeof(instr));
        cipher = charToBitset(instr);
        if(*instr == '\0') break;
//        cout << decipher(cipher) << "\n";
        outstr = bitsetToChar(decipher(cipher));
//        cout << outstr << "\n";
        fout.write(outstr, sizeof(outstr));
    }
    fin.close();
    fout.close();
    return 0;
}