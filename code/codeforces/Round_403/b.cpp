
#include<bits/stdc++.h>
using namespace std;
//#define ONLINE_JUDGE

#define eps 1e-7
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
double maxtime, mintime;
const int maxn = 60010;
struct Peo{
    int x;
    int v;
}p[maxn];

bool cmp(Peo u, Peo v) {
    return u.x < v.x;
}

double GetMaxTime() {
    double left = p[0].x; double right = p[n - 1].x;
    double ans = -1.0;
    rep(i, 1, n) {
	ans = Max(ans, (p[i].x - left) / p[i].v * 1.0);
	ans = Max(ans, (right - p[i].x) / p[i].v * 1.0);
    }
    return ans;
}

void Init() {
    rep(i, 0, n) sf(p[i].x);
    rep(i, 0, n) sf(p[i].v);
    sort(p, p + n, cmp);
    maxtime = GetMaxTime();
    mintime = 0.0;
}

bool check(double ti) {
    double leftmost = p[0].x - p[0].v * ti;
    double rightmost = p[0].x + p[0].v * ti;
    rep(i, 1, n) {
	double l = p[i].x - p[i].v * ti;
	double r = p[i].x + p[i].v * ti;
	leftmost = Max(l, leftmost);
	rightmost = Min(r, rightmost);
	if(leftmost - rightmost > eps) return false;
    }
    return true;
}

double solve() {
    double ans = INF;
    double low = mintime;
    double high = maxtime;
    while(abs(high - low) > eps) {
	double mid = (low + high) / 2;
	if(check(mid)) {
	    ans = Min(ans, mid);
	    high = mid;
	} else {
	    low = mid;
	}
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sf(n)) {
	Init();
	printf("%.12lf\n", solve());
    }
    return 0;
}
