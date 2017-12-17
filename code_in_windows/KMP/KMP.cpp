/*************************************************************************
    > File Name: KMP.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/3/30 星期三 下午 7:46:54
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<map>
#include<set>
using namespace std;
//#define ONLINE_JUDGE
#define eps 1e-8
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define rep(i,a) for((i)=0; i<(a);(i)++)
#define mem(a,b) (memset((a),b,sizeof(a)))
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfs(a) scanf("%s",a)
#define pf(a) printf("%d\n",a)
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%I64d\n",a)
#define LL __int64
const double PI = acos(-1.0);
const double E = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b)*b; }
template<class T> inline T Min(T a, T b) { return a<b ? a : b; }
template<class T> inline T Max(T a, T b) { return a>b ? a : b; }
int n, m;
#define N 1000
char souce[N];
char aim[N];
int table[N];
void Get_Table() {                              //用来替代NEXT数组的表，最大前缀后缀长度相等长度的表
    table[0] = 0;                               //NEXT[0] = -1，I : 0 -> LEN  NEXT[I] = TABLE[I - 1]
    int aLen = strlen(aim);
    for(int i = 1, j = 0; i < aLen; i++) {
        j = table[i - 1];
        table[i] = (aim[i] == aim[j] ? table[i - 1] + 1 : 0);
    }
    return ;
}
int KMP() {
    int sLen = strlen(souce);
    int aLen = strlen(aim);
    int i = 0, j = 0;
    while(i < sLen && j < aLen) {               //比较和移位的过程
        if(souce[i] == aim[j]) {                //如果匹配就继续比较后面一个
            i++;
            j++;
        }
        else {
            if(!j) {                            //模式串的第0个就和文本串不匹配的情况
                i++;
            }
            else {
                j = table[j - 1];               //匹配失败但是不是第0个，文本串位置不变，模式串移位
           }
        }
    }
    if(i == sLen && j != aLen) {                //文本串已到最后，但是模式串没到最后
        return -1;                              //return -1表示匹配失败
    }
    return i - j;                               //匹配成功，返回在文本串中第一次匹配成功的位置（从0开始）
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("Out.txt", "w", stdout);
#endif
    while(gets(souce) != NULL) {
        gets(aim);
        Get_Table();
		for(int i = 0; i < 8; i++) {
			printf("%d%c", table[i], (i == 7 ? '\n' : ' '));
		}
        //pf(KMP());
		//system("PAUSE");
    }
	return 0;
}
