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
const int maxn = 100000 + 5;
char str[maxn];
int cnt[maxn];

void Init() {
	cnt[0] = 0;
	sfd(n, m);
	sfs(str + 1);
	//pfs(str + 1);
	repe(i, 1, n) cnt[i] = cnt[i - 1] + (str[i] == '1');
	//repe(i, 1, n) printf("%d%c", cnt[i], (i == n ? '\n' : ' '));
}

void solve() {
	int minlen = m;
	int sp = 1, len = m;
	int maxd = m, maxu = cnt[m];
	repe(i, 1, n - m + 1) {
		for(int l = m; i + l - 1 <= n; l++) {
			int up = cnt[i + l - 1] - cnt[i - 1];
			int dn = l;
			if(maxd * up > maxu * dn) {
				maxd = dn; maxu = up;
				minlen = l;
				sp = i;
			}
		}
	}
	pfd(sp, sp + minlen - 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    dsD(t) {
    	Init();
    	solve();
    }
    return 0;
}