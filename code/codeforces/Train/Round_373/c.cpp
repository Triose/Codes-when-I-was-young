/*************************************************************************
    > File Name: c.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年09月25日 星期日 13时38分14秒
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
const int maxn = 200010;
int pos;
string dp[maxn][2];
string numb;

string round(string str, int p) {
    string ans = str;
    putchar(str[p]); enter;
    if(ans[p] > '4') {
	if(ans[p - 1] != '9') ans[p - 1]++;
	else {
	    int i = pos - 1;
	    while(ans[i] == '9') ans[i--] = 0;
	    if(i == pos) {
		i--;
		while(ans[i] == '9') ans[i--] = '0';
		if(!i) {
		    ans = "1" + ans;
		}
		else {
		    ans[i]++;
		}
	    }
	    else {
		ans[i]++;
	    }
	}
    }
    int i = p;
    for(; i > pos; i--) {
	if(str[i] != '0') return ans.substr(0, i + 1); 
    }
    return ans.substr(0, pos);
}

void solve() {
    int times = 0;
    dp[n - 1][0] = numb; dp[n - 1][0] = round(numb, n - 1);
    per(i, n - 1, pos) {

    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    isws;
    /*
    while(cin >> n >> m) {
	cin >> numb;
	pos = numb.find_first_of('.');
	if(pos == -1) cout << numb << "\n";
	else {

	}
    }
    // */
    cout << round("6.39995", 6) << endl;
    return 0;
}
