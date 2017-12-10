/*************************************************************************
    > File Name: 3468.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年08月03日 星期三 16时35分43秒
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
#define sfI(a) scanf("%lld",&a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfs(a) scanf("%s",a)
#define pf(a) printf("%d\n",a)
#define pfd(a,b) printf("%d %d\n",a,b)
#define pfP(a) printf("%d %d\n",a.fi,a.se)
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%lld\n",a)
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
#define N 100010
LL a[N];
struct Elmt {
    int l, r;
    LL sum;
    LL add;
    Elmt() {
	l = 0; r = 0;
	sum = 0;
	add = 0;
    }
};
Elmt tree[N * 4];
void Build(int root, int s, int e) {
    if(s == e) {
	tree[root].l = tree[root].r = s;
	tree[root].sum = a[s]; tree[root].add = 0;
	return ;
    }
    tree[root].l = s; tree[root].r = e;
    int mid = (s + e) >> 1;
    Build(root * 2 + 1, s, mid);
    Build(root * 2 + 2, mid + 1, e);
    tree[root].sum = tree[root * 2 + 1].sum + tree[root * 2 + 2].sum;
    tree[root].add = 0;
    return ;
}
void Adto(int root, int s, int e, LL dter) {
    if(tree[root].l == s && tree[root].r == e) {
	tree[root].add += dter;
	return ;
    }
    tree[root].sum += dter * (e - s + 1);//维护sum！！！
    int mid = (tree[root].l + tree[root].r) >> 1;
    if(e <= mid) {
	Adto(root * 2 + 1, s, e, dter);
    }
    else if(s > mid) {
	Adto(root * 2 + 2, s, e, dter);
    }
    else {
	Adto(root * 2 + 1, s, mid, dter);
	Adto(root * 2 + 2, mid + 1, e, dter);
    }
}
LL Query(int root, int s, int e) {
    if(tree[root].l == s && tree[root].r == e) {
	return tree[root].sum + (tree[root].r - tree[root].l + 1) * tree[root].add;//注意！每一个都加了
    }
    tree[root * 2 + 1].add += tree[root].add;
    tree[root * 2 + 2].add += tree[root].add;
    tree[root].sum += ((tree[root].r - tree[root].l + 1) * tree[root].add);//更新sum
    tree[root].add = 0;//更新增量
    int mid = (tree[root].l + tree[root].r) >> 1;
    if(e <= mid) {
	return Query(root * 2 + 1, s, e);
    }
    else if(s > mid) {
	return Query(root * 2 + 2, s, e);
    }
    else {
	return Query(root * 2 + 1, s, mid) + Query(root * 2 + 2, mid + 1, e);
    }
}
char order[5];
int s, e;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfd(n, m)) {
	repe(i, 1, n) sfI(a[i]);
	Build(0, 1, n);
	while(m--) {
	    scanf("%s%d%d", order, &s, &e);
	    if(order[0] == 'Q') {
		pfI(Query(0, s, e));
	    }
	    else {
		LL dter; sfI(dter);
		Adto(0, s, e, dter);
	    }
	}
    }
    return 0;
}
