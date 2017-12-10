/*************************************************************************
    > File Name: c.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年07月14日 星期四 09时26分57秒
 ************************************************************************/

//#include<bits/stdc++.h>
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
#include<time.h>
#include<map>
#include<set>
using namespace std;
//#define ONLINE_JUDGE
#define eps 1e-8
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define enter putchar(10)
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define repe(i,a,b) for(int i = (a); i <= (b); ++i)
#define mem(a,b) (memset((a),b,sizeof(a)))
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfs(a) scanf("%s",a)
#define pf(a) printf("%d\n",a)
#define pfd(a,b) printf("%d %d\n",a,b)
#define pfP(a) printf("%d %d\n",a.fi,a.se)
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%I64d\n",a)
#define PR(a,b) pair<a,b>
#define fi first
#define se second
#define LL long long
#define DB double
const double PI = acos(-1.0);
const double E = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }
int n, m;
int main() {
#ifndef ONLINE_JUDGE
//   freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sf(n)) {
	if(n < 4) {
	    pfs("NO");
	    continue;
	}
	pfs("YES");
	if(n % 4 == 0) {
	    pfs("1 * 2 = 2");
	    pfs("2 * 3 = 6");
	    pfs("4 * 6 = 24");
	}
	else if(n % 4 == 1) {
	    pfs("4 * 5 = 20");
	    pfs("2 + 3 = 5");
	    pfs("5 - 1 = 4");
	    pfs("20 + 4 = 24");
	}
	else if(n % 4 == 2) {
	    pfs("2 * 3 = 6");
	    pfs("4 - 1 = 3");
	    pfs("6 + 3 = 9");
	    pfs("9 - 5 = 4");
	    pfs("4 * 6 = 24");
	}
	else {
	    pfs("1 - 2 = -1");
	    pfs("4 + -1 = 3");
	    pfs("3 + 3 = 6");
	    pfs("6 + 5 = 11");
	    pfs("11 + 6 = 17");
	    pfs("17 + 7 = 24");
	}
	while(n >= 8) {
	    printf("%d - %d = 1\n", n, n - 1);
	    printf("%d - %d = -1\n", n - 3, n - 2);
	    printf("1 + -1 = 0\n");
		pfs("24 + 0 = 24");
	    n -= 4;
	}
    }
    return 0;
}
