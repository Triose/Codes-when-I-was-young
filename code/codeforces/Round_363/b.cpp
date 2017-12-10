/*************************************************************************
    > File Name: b.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年07月19日 星期二 21时52分17秒
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
PR(int, int) p[N];
int line[N], raw[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfd(n, m)) {
	repe(i, 1, n) sfs(pic[i] + 1);
	int cnt = 0;
	int max_l = 0; int max_r = 0;
	int r = -1, l = -1;
	mem(line, 0); mem(raw, 0);
	repe(i, 1, n) {
	    repe(j, 1, m) {
		if(pic[i][j] == '*') {
		    p[cnt].fi = i; p[cnt].se = j;
		    line[i]++; raw[j]++;
		    if(line[i] > max_l) {
			max_l = line[i];
			l = i;
		    }
		    if(raw[j] > max_r) {
			max_r = raw[j];
			r = j;
		    }
		    cnt++;
		}
	    }
	}
	int i = 0;
	for(i = 0; i < cnt; i++) {
	   if(p[i].fi != l && p[i].se != r) break; 
	}
	if(i !=  cnt && cnt != 0) pfs("NO");
	else {
	    pfs("YES");
	    pfd((cnt == 0 ? 1 : l),(cnt == 0 ? 1 : r));
	}
    }
    return 0;
}
