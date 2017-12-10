/*************************************************************************
    > File Name: p3264.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年07月26日 星期二 08时58分17秒
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
#define N 200010
int maxq, minq;
int a[N];
struct Elmt {
    int s, e;
    int maxn, minn;
    Elmt * left, * right;
    Elmt(int s, int e) {
	this->s = s; this->e = e;
	this->maxn = -1; this->minn = INF;
	left = NULL; right = NULL;
    }
};
Elmt * tree;
void build(Elmt * elmt) {
    if(elmt->s == elmt->e) {
	elmt->maxn = a[elmt->s];
	elmt->minn = a[elmt->e];
	return ;
    }
    else {
	int mid = (elmt->s + elmt->e) >> 1;
	if(!elmt->left)
	    elmt->left = new Elmt(elmt->s, mid);
	else {
	    elmt->left->s = elmt->s; elmt->left->e = mid;
	}
	if(!elmt->right)
	    elmt->right = new Elmt(mid + 1, elmt->e);
	else {
	    elmt->right->s = mid + 1; elmt->right->e = elmt->e;
	}
	build(elmt->left); build(elmt->right);
	elmt->maxn = Max(elmt->left->maxn, elmt->right->maxn);
	elmt->minn = Min(elmt->left->minn, elmt->right->minn);
	return ;
    }
}
void collapse(Elmt * elmt) {
    if(!elmt) return ;
    collapse(elmt->left);
    collapse(elmt->right);
    delete elmt;
    return ;
}

void query(Elmt * elmt, int s, int e) {
    if(elmt->s == s && elmt->e == e) {
	maxq = Max(elmt->maxn, maxq);
	minq = Min(elmt->minn, minq);
	return ;
    }
    int mid = (elmt->s + elmt->e) >> 1;
    if(e <= mid) {
	query(elmt->left, s, e);
    }
    else if(s > mid) {
	query(elmt->right, s, e);
    }
    else {
	query(elmt->left, s, mid);
	query(elmt->right, mid + 1, e);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfd(n, m)) {
	repe(i, 1, n) sf(a[i]);
	tree = new Elmt(1, n);
	build(tree);
	int l, r;
	while(m--) {
	    sfd(l, r);
	    maxq = -1; minq = INF;
	    if(l == r) {
		pf(0);continue;
	    }
	    query(tree, l, r);
	    pf((maxq - minq));
	}
	//collapse(tree);
    }
    return 0;
}
