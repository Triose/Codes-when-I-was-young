/*************************************************************************
    > File Name: d.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年07月16日 星期六 22时37分17秒
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
int x1, x2, y11, y2;
char s[2];
#define N 110
int pic[N][N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    int _, t;
    cin >> _;
    while(_--) {
	mem(pic, 0);
	cin >> n >> m >> t;
	while(t--) {
	    cin >> x1 >> y11 >> x2 >> y2 >> s;
	    repe(i, x1, x2) {
		repe(j, y11, y2) {
		    pic[i][j] = s[0];
		}
	    }
	}
	repe(i, 1, n) {
	    repe(j, 1, m) {
		putchar((pic[i][j] == 0 ? '.' : pic[i][j]));
	    }
	    enter;
	}
    }
    return 0;
}
