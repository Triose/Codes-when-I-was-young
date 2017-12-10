/*************************************************************************
    > File Name: 2141.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年08月07日 星期日 15时04分36秒
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
#define N 510
LL a[N], b[N], c[N];
int al, bl, cl;
LL sum[N * N];
int cas = 0;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~scanf("%d%d%d", &al, &bl, &cl)) {
	rep(i, 0, al) sfI(a[i]);
	rep(i, 0, bl) sfI(b[i]);
	rep(i, 0, cl) sfI(c[i]);
	int cnt = 0;
	cas = 0;
	rep(i, 0, al) {
	    rep(j, 0, bl) {
		sum[cnt++] = a[i] + b[j];
	    }
	}
	int sl = unique(sum, sum + cnt) - sum;
	sort(c, c + cl);
	sf(n);
	LL res;
	printf("Case %d:\n", ++cas);
	while(n--) {
	    scanf("%I64d", &res);
	    int j = 0;
	    for(j = 0; j < sl; j++) {
		int p = lower_bound(c, c + cl, res - sum[j]) - c;
		if(c[p] == res - sum[j]) {
		    pfs("YES");
		    break;
		}
	    }
	    if(j == sl) {
		pfs("NO");
	    }
	}
    }
    return 0;
}
