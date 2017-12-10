/*************************************************************************
    > File Name: 1305.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年07月09日 星期六 14时45分33秒
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
#define N 1000010
bool vis[N];
void solve() {
    mem(vis, false);
    int ans1 = 0, ans2 = 0;
    int s = 3, t = 1;
    while(s * s + 1 <= 2 * n) {
	t = 1;
	while(t < s) {
	    if(s * s + t * t <= 2 * n && gcd(s, t) == 1) {
		int a = s * t, b = (s * s - t * t) / 2, c = (s * s + t * t) / 2;
		ans1++;
		for(int i = 1; i * c <= n; i++) {
		    vis[i * a] = true; vis[i * b] = true; vis[i * c] = true;
		}
	    }
	    t += 2;
	}
	s += 2;
    }
    repe(i, 1, n) {
	if(!vis[i]) ans2++;
    }
    pfd(ans1, ans2);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sf(n)) {
	solve();
    }
    return 0;
}
