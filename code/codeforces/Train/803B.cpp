
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

const int maxn = 200010;
int a[maxn], cnt[maxn];

void Init() {
    cnt[0] = 0; a[0] = 1000;
    repe(i, 1, n) {
	sf(a[i]);
	cnt[i] = (a[i] ? cnt[i - 1] : cnt[i - 1] + 1);
    }
}

int getAns(int pos) {
    if(!a[pos]) return 0;
    int len = n + 1;
    int low = 1, high = n;
    while(low <= high) {
	int mid = (low + high) >> 1;
	int left = (pos - mid > 0 ? pos - mid : 1);
	int right = (pos + mid <= n ? pos + mid : n);
	if(cnt[pos] - cnt[left - 1]) {
	    len = Min(len, pos - left);
	    high = mid - 1;
	    continue;
	}
	if(cnt[right] - cnt[pos - 1]) {
	    len = Min(len, right - pos);
	    high = mid - 1;
	    continue;
	}
	low = mid + 1;
    }
    return len;
}

void solve() {
    repe(i, 1, n) {
	printf("%d%c", getAns(i), (i == n ? '\n' : ' '));
    }
}

void debugg() {
    repe(i, 1, n) printf("%d%c", a[i], (i == n ? '\n' : ' '));
    repe(i, 1, n) printf("%d%c", cnt[i], (i == n ? '\n' : ' '));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sf(n)) {
	Init();
	solve();
	//debugg();
    }
    return 0;
}
