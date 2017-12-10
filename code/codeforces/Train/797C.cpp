
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
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scpy(str1, str2) strcpy(str1, str2)
#define sfs(a) scanf("%s",a)
#define pf(a) printf("%d\n",a)
#define pfd(a,b) printf("%d %d\n",a,b)
#define pfP(a) printf("%d %d\n",a.fi,a.se)
#define pfs(a) printf("%s\n",a)
#define mem(a,b) memset((a),b,sizeof(a))

#define fi first
#define se second
#define DB double
#define isws ios::sync_with_stdio(false)
const double PI = acos(-1.0);
const double E = exp(1.0);

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }

int n, m;
const int maxn = 100010;
char str[maxn];
int len;
struct Node {
    int left, right;
    int pos;
    Node(int l_ = 0, int r_ = 0, int p_ = 0) {
	left = l_; right = r_;
	pos = p_;
    }
    int mid() {
	return (left + right) >> 1;
    }
}tree[maxn * 8];

void BuildTree(int root, int l, int r) {
    tree[root].left = l; tree[root].right = r;
    if(l == r) {
	tree[root].pos = l;
	return ;
    }
    int mid = (l + r) >> 1;
    BuildTree(root * 2 + 1, l, mid);
    BuildTree(root * 2 + 2, mid + 1, r);
    tree[root].pos = (str[tree[root * 2 + 1].pos] <= str[tree[root * 2 + 2].pos] ? tree[root * 2 + 1].pos : tree[root * 2 + 2].pos);
    return ;
}

int Query(int root, int l, int r) {
    if(l == tree[root].left && r == tree[root].right) return tree[root].pos;
    int mid = tree[root].mid();
    if(r <= mid) return Query(root * 2 + 1, l, r);
    else if(l > mid) return Query(root * 2 + 2, l, r);
    int p1 = Query(root * 2 + 1, l, mid);
    int p2 = Query(root * 2 + 2, mid + 1, r);
    return (str[p1] <= str[p2] ? p1 : p2);
}

void Init() {
    len = slen(str);
    BuildTree(0, 0, len - 1);
}

void reversePrint(int l, int r) {
    //pfs("rsP: "); pfd(l, r);
    per(i, r - 1, l) putchar(str[i]);
}

void solve(int l, int r) {
    //pfs("s:");pfd(l, r);
    if(l <= r) {
	int minpos = Query(0, l, r);
	if(minpos == l) putchar(str[minpos]), solve(l + 1, r);
	else if(minpos == r) putchar(str[r]), reversePrint(l, r);
	else {
	    putchar(str[minpos]);
	    solve(minpos + 1, r);
	    reversePrint(l, minpos);
	}
    }
    return ;
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfs(str)) {
	Init();
	solve(0, len - 1);
	enter;
    }
    return 0;
}
