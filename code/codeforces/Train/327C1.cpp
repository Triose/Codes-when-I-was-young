/*************************************************************************
    > File Name: 327C1.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年08月01日 星期一 10时29分31秒
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
#define ds(a) int a; sf(a)
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
#define N 100010
const LL MOD = (1e+9) + 7;
char str[N];
int len;

LL PowMod(LL A, LL T, LL mod) {		// A ^ T % mod
    LL res = 1;
    LL base = A % mod;
    while(T) {
	if(T & 1) 
	    res = (res * base) % mod;
	base = (base * base) % mod;
	T >>= 1;
    }
    return res;
}

LL PowSumMod(LL q, LL T, LL mod) {	// (q ^ 1 + .... + q ^ T) % mod
    if(T == 0) return 0;
    if(T == 1) return q % mod;
    if(T % 2 == 0) {
	return (((PowMod(q, T / 2, mod) + 1) % mod) * PowSumMod(q, T / 2, mod)) % mod;
    }
    else {
	return ((((PowMod(q, T / 2, mod) + 1) % mod) * PowSumMod(q, T / 2, mod)) % mod + 
		PowMod(q, T, mod)) % mod;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfs(str + 1)) {
	sf(n);
	len = strlen(str + 1);
	LL q = PowMod(2, len, MOD);
	LL sum = PowSumMod(q, n - 1, MOD);
	sum = (sum + 1) % MOD;
	LL ans = 0;
	repe(i, 1, len) {
	    if(str[i] == '0' || str[i] == '5') {
		LL tmp = PowMod(2LL, i - 1, MOD);
		tmp = (tmp * sum) % MOD;
		ans = (ans + tmp) % MOD;
	    }
	}
	pfI(ans);
    }
    return 0;
}
