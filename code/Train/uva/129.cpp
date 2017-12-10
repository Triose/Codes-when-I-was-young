/*************************************************************************
    > File Name: 129.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年10月29日 星期六 20时46分06秒
 ************************************************************************/

#include<bits/stdc++.h>
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
const int maxn = 100;
char str[maxn];
bool done;

bool check(int pos) {
    for(int i = 1; i * 2 <= pos + 1; i++) {
	bool flag = true;
	for(int j = 0; j < i; j++) {
	    if(str[pos - j] != str[pos - i - j]) {
		flag = false;
		break;
	    }
	}
	if(flag) return false;
    }
    return true;
}

void dfs(int pos, int & th) {
    if(th == n) {
	str[pos] = '\0';
	done = true;
	return ;
    }
    rep(i, 0, m) {
	str[pos] = 'A' + i;
	if(check(pos)) {
	    dfs(pos + 1, ++th);
	    if(done) return ;
	}
    }
}


void print() {
    int cnt = 0;
    int len = slen(str);
    rep(i, 0, len) {
	putchar(str[i]);
	if(i % 4 == 3) {
	    cnt++;
	    if(cnt % 16 == 0) enter;
	    else if(i != len - 1) putchar(' ');
	}
	if(i == len - 1) {
	    if(i % 4 == 3 && cnt % 16 == 0) {

	    }
	    else {
		enter;
	    }
	}
    } 
    pf(len);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfd(n, m)) {
	if(!n && !m) break;
	done = false;
	int th = 0;
	dfs(0, th);
	print();
    }
    return 0;
}
