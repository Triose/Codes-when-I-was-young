/*************************************************************************
    > File Name: main.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/4/14 星期四 下午 4:15:31
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
#define pfd(a,b) printf("%d %d\n",a,b)
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
double table[4] = {12.01, 1.008, 16.00, 14.01};
#define N 100
char str[N];
double ans;
int len;
int getm(int pos) {
	if(pos == len)
		return 1;
	if(str[pos] >= 'A' && str[pos] <= 'Z') {
		return 1;
	}
	int num = 0;
	while(str[pos] >= '1' && str[pos] <= '9' && pos < len) {
		num += (str[pos] - '0');
		pos++;
		if(str[pos] >= '1' && str[pos] <= '9') {
			num *= 10;
		}
	}
	return num;
}
void solve() {
	ans = 0;
	len = strlen(str);
	for(int i = 0; i < len; i++) {
		int tmp = 0;
		switch (str[i]) {
			case 'C' : ans += (table[0] * getm(i + 1)); break;
			case 'H' : ans += (table[1] * getm(i + 1)); break;
			case 'O' : ans += (table[2] * getm(i + 1)); break;
			case 'N' : ans += (table[3] * getm(i + 1)); break;
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("Out.txt", "w", stdout);
#endif
	int _;
	sf(_);
	while(_--) {
		sfs(str);
		solve();
		printf("%.3lf\n", ans);
	}
	return 0;
}

