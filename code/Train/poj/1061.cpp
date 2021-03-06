/*************************************************************************
    > File Name: 1061.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年07月10日 星期日 10时22分37秒
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
LL exgcd(LL a, LL b, LL & x, LL & y) {
    if(!b) {
	x = 1; y = 0;
	return a;
    }
    LL d = exgcd(b, a % b, x, y);
    LL t = x; x = y; y = t - (a / b) * y;
    return d;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    LL x, y, n, m, l;
    LL a, b;
    while(~scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l)) {
	LL t, g;
	g = exgcd(n - m, l, a, b);
	if((x - y) % g != 0) pfs("Impossible");
	else {
	    LL ans = (x - y) * a / g;
	    LL tmp = l / g;
	    ans = (ans % tmp + tmp) % tmp;
	    printf("%lld\n", ans);
	}
    }
    return 0;
}
