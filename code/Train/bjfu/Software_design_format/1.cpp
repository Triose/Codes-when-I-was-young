/*************************************************************************
    > File Name: 1.cpp
    > Author: Triose
    > Mail: Triose@163.com
    > Created Time: 2016年09月18日 星期日 19时54分38秒
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
#define sfI(a) scanf("%I64d",&a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scpy(str1, str2) strcpy(str1, str2)
#define sfs(a) scanf("%s",a)
#define pf(a) printf("%d\n",a)
#define pfd(a,b) printf("%d %d\n",a,b)
#define pfP(a) printf("%d %d\n",a.fi,a.se)
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%I64d\n",a)
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

bool cmp(int a, int b) {
    return a < b;
}

template<class T>
void msort(T *arr, int l, int r, bool  (*cmp)(T, T )) {
    if(l >= r) return ;
    T value = arr[l];
    int i = l, j = r;
    while(i < j) {
    	for(; i < j; j--) if(!cmp(value, arr[j])) { arr[i++] = arr[j]; break; }
    	for(; i < j; i++) if(cmp(value, arr[i])) { arr[j--] = arr[i]; break; }
    }
    arr[i] = value;
    msort(arr, l, i - 1, cmp);
    msort(arr, i + 1, r, cmp);
}


int main() {
#ifndef ONLINE_JUDGE
//  freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    srand(time(NULL));
    int a[15];
    rep(i, 0, 10) {
	a[i] = rand() % 30;
	printf("%d ", a[i]);
    }
    enter;
    msort(a, 0, 9, cmp);
    rep(i, 0, 10) printf("%d ", a[i]);
    enter;
    return 0;
}

