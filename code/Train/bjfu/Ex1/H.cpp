
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

int n, m, k;
const int maxn = 2010;
int dp[maxn][maxn];
char s1[maxn];
char s2[maxn];
int len1, len2;

int diff(int t) {
    return t > 0 ? t : -t;
}

void Init() {
	mem(dp, 0);
    len1 = slen(s1);
    len2 = slen(s2);
    dp[0][0] = 0;
    repe(i, 1, len1) dp[i][0] = i * k;
    repe(i, 1, len2) dp[0][i] = i * k;
    repe(i, 1, len1) repe(j, 1, len2) {
	dp[i][j] = Min(dp[i - 1][j - 1] + diff(s1[i - 1] - s2[j - 1]), Min(dp[i - 1][j], dp[i][j - 1]) + k); 
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(cin >> s1 >> s2 >> k) {
	Init();
	pf(dp[len1][len2]);
    }
    return 0;
}
