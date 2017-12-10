/*************************************************************************
    > File Name: zipper.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年07月23日 星期六 14时39分57秒
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
char s1[N], s2[N], s[N];
int len1, len2, len;
int dp[N][N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    int t;sf(t);
    repe(l, 1, t) {
	sfs(s1 + 1); sfs(s2 + 1); sfs(s + 1);
	len1 = strlen(s1 + 1);
	len2 = strlen(s2 + 1);
	len = strlen(s + 1);
	dp[0][0] = 1;
	rep(i, 0, len1) {
	    rep(j, 0, len2) {
		if(i == 0 && j == 0) continue;
		if(s[i + j] == s1[i]) 
		    dp[i + 1][j] |= dp[i][j];
		if(s[i + j] == s2[j])
		    dp[i][j + 1] |= dp[i][j];
	    }
	}
	pf(dp[len1][len2]);
    }
    return 0;
}
