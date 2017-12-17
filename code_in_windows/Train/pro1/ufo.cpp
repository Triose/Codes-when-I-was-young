/*************************************************************************
    ID:triose1
    PROG:ride
    LANG:C++
 ************************************************************************/
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

#define N 10
char souce[N];
char aim[N];

int fast_mod(char *str) {
    int num = 1;
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        num = (num * ((str[i] - 'A') + 1)) % 47;
    }
    return num % 47;
}



int main() {
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    fin >> souce >> aim;
    if(fast_mod(souce) == fast_mod(aim)) {
        fout << "GO" << endl;
    }
    else {
        fout << "STAY" << endl;
    }
    return 0;
}
