/*************************************************************************
    > File Name: E.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年10月20日 星期四 20时44分48秒
 ************************************************************************/

//#include<bits/stdc++.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string.h>
#include <iterator>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//#define ONLINE_JUDGE

#define eps 1e-8
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define enter putchar(10)

#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define per(i,a,b) for(int i = (a); i >= (b); --i)
#define repe(i,a,b) for(int i = (a); i <= (b); ++i)
#define ECH(it, A) for (typeof(A.begin()) it=A.begin(); it != A.end(); ++it)

#define PR(a,b) pair<a,b>
#define slen(str) strlen(str)
#define ds(t) int t; sf(t)
#define Down(t) while(t--)
#define dc(t) int t; cin >> t;
#define dsD(t) ds(t); Down(t)
#define dcD(t) dc(t); Down(t)
#define ALL(A) A.begin(), A.end()
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%lld",&a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scpy(str1, str2) strcpy(str1, str2)
#define sfs(a) scanf("%s",a)
#define pf(a) printf("%d\n",a)
#define pfd(a,b) printf("%d %d\n",a,b)
#define pfP(a) printf("%d %d\n",a.fi,a.se)
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%lld\n",a)
#define mem(a,b) memset((a),b,sizeof(a))

#define fi first
#define se second
#define LL long long
#define DB double
#define isws ios::sync_with_stdio(false)
const double PI = acos(-1.0);
const double E = exp(1.0);

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }

int n, m;
const int mod = (1e+8)+7;
const int maxn = 10010;
char str[maxn];
int a[maxn];
LL dp[maxn][5];

void Init() {
    sfs(str);
    n = slen(str);
    rep(i, 0, n) a[i] = (str[i] - '0');
    mem(dp, 0);
    if(a[0] == 3) dp[0][1] = 2, dp[0][2] = 1;
    else if(a[0] == 2) dp[0][0] = 1, dp[0][1] = 2, dp[0][2] = 1;
    else if(a[0] == 1) dp[0][0] = 1, dp[0][1] = 2;
    else if(a[0] == 0) dp[0][0] = 1;
}

LL solve() {
    rep(i, 1, n) {
	repe(j, 0, Min(2, a[i])) {
	    dp[i][j] = (dp[i - 1][a[i] - j] * (j == 1 ? 2 : 1)) % mod;
	}
    }
    LL ret = 0;
    rep(i, 0, 5) ret = (ret + dp[n - 1][i]) % mod;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    dsD(t) {
	Init();
	pfI(solve());
    }
    return 0;
}
