/*************************************************************************
    > File Name: ul4329.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年10月18日 星期二 20时24分08秒
 ************************************************************************/

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

int n, m;
const int maxn = (1e+4) + 10;
const int maxm = (1e+5) + 10;
LL tree[maxm * 4], a[maxn];
LL lfl[maxn], rgl[maxn];

void Init() {
    sf(n);
    rep(i, 0, n) sfI(a[i]), lfl[i] = 0, rgl[i] = 0;
}

void Ins(int root, int left, int right, int pos) {
    tree[root]++;
    if(left == right)  return ;
    int mid = (left + right) >> 1;
    if(pos <= mid) Ins(root * 2 + 1, left, mid, pos);
    else Ins(root * 2 + 2, mid + 1, right, pos);
}

LL Query(int root, int rl, int rr, int l, int r) {
    if(rl == rr) return tree[root];
    int mid = (rl + rr) >> 1;
    if(r <= mid) return Query(root * 2 + 1, rl, mid, l, r);
    else if(r > mid) return Query(root * 2 + 2, mid + 1, rr, l, r);
    return Query(root * 2 + 1, rl, mid, l, mid) + Query(root * 2 + 2, mid + 1, rr, mid + 1, r);
}

LL solve() {
    LL ans = 0;
    mem(tree, 0);
    rep(i, 0, n) {
	if(a[i] > 0)
	    lfl[i] = Query(0, 0, maxm, 0, a[i] - 1);
	Ins(0, 0, maxm, a[i]);
    }
    mem(tree, 0);
    per(i, n - 1, 0) {
	rgl[i] = Query(0, 0, maxm, a[i] + 1, maxm);
	Ins(0, 0, maxm, a[i]);
    }
    rep(i, 1, n) ans += ((lfl[i] * rgl[i]) + ((i - lfl[i]) * (n - i - 1 - rgl[i])));
    return ans;
}

void check() {
    pfI(tree[0]);
    rep(i, 0, n) printf("%lld %lld %lld\n", a[i], lfl[i], rgl[i]);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    dsD(t) {
	Init();
	pfI(solve());
	check();
    }
    return 0;
}
