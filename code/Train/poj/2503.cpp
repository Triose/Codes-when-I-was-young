/*************************************************************************
    > File Name: 2503.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年06月11日 星期六 22时42分37秒
 ************************************************************************/

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
#define INF 0x7fffffff
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define inf 0x3f3f3f3f
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
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%I64d\n",a)
#define enter putchar(10)
#define PR<a,b> pair<a,b>
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
const int N = 1e+5;
PR<string,string> dict[N];
string str;
char ch;
int countt;
string aim[N];
int acountt;
bool cmp(PR & a, PR & b) {
    return a.se < b.se;
}
int brain_search(string str) {
    int low = 0, high = count - 1;
    while(low <= high) {
	int mid = (low + high) >> 1;
	if(dict[mid].se == str) return mid;
	else if(dict[mid].se > str) high = mid - 1;
	else low = mid + 1;
    }
    return -1;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    countt = 0;
    acountt = 0;
    while(cin >> str) {
	cin >> ch;
	if(ch == '\n') {
	   aim[acountt++] = str;
	}
	else {
	    dict[countt].fi = str;
	    cin >> dict[countt++].se;
	}
    }
    sort(dict, dict + countt, cmp);
    rep(i,0,acountt) {
	int ans = brain_search(aim[i]);
	if(ans == -1) cout << "en\n";
	else cout << dict[ans].fi << "\n";
    }
    return 0;
}
