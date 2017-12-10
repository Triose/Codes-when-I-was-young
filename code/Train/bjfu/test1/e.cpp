/*************************************************************************
    > File Name: e.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年07月11日 星期一 15时00分59秒
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
#define N 1010
char pic[N][N];
int ans[2];
char aim[2][5] = {
    {'g', 'i', 'r', 'l'}, {'c', 'a', 't'}
};

bool jud(int x, int y, int t, int pos) {
    if(x >= n || x < 0) return false;
    if(y >= m || y < 0) return false;
    if(pic[x][y] == aim[t][pos]) return true;
    return false;
}

int dfs(int i, int j, int t, int pos) {
    if(t == 0 && pos == 4) return 1;
    if(t == 1 && pos == 3) return 1;
    int ans = 0;
    for(int x = -1; x < 2; x++) {
	for(int y = -1; y < 2; y++) {
	    if(x == y || x == -y) continue;
	    if(jud(i + x, j + y, t, pos)) {
		ans += dfs(i + x, j + y, t, pos + 1);
	    }
	}
    }
    return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    int t;
    sf(t);
    while(t--) {
	mem(ans, 0);
	sfd(n, m);
	rep(i, 0, n) sfs(pic[i]);
	rep(i, 0, n) {
	    rep(j, 0, m) {
		if(pic[i][j] == 'g') ans[0] += dfs(i, j, 0, 1);
		else if(pic[i][j] == 'c') ans[1] += dfs(i, j, 1, 1);
	    }
	}
	pfd(ans[0], ans[1]);
    }
    return 0;
}
