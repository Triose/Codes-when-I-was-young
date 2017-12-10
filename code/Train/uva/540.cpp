/*************************************************************************
    > File Name: 540.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年08月16日 星期二 22时02分01秒
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
#define ALL(t) t.begin(), t.end()
#define INS(t) inserter(t, t.begin())
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
map<int, int> team;
queue<int> Q, q[1010];
void Init() {
    team.clear();
    while(!Q.empty()) Q.pop();
    rep(i, 0, 1010) {
	while(!q[i].empty()) q[i].pop();
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    int cas = 1;
    while(~sf(n) && n) {
	Init();
	printf("Scenario #%d\n", cas++);
	rep(i, 0, n) {
	    sf(m);
	    rep(j, 0, m) {
		int tmp;
		sf(tmp);
		team[tmp] = i;
	    }
	}
	char od[20];
	while(sfs(od)) {
	    if(*od == 'S') break;
	    if(*od == 'E') {
		int tmp;
		sf(tmp);
		if(q[team[tmp]].empty()) Q.push(team[tmp]);
		q[team[tmp]].push(tmp);
	    }
	    else {
		int tm = Q.front();
		pf(q[tm].front()); q[tm].pop();
		if(q[tm].empty()) Q.pop();
	    }
	}
	enter;
    }
    return 0;
}
