/*************************************************************************
    > File Name: 1354C.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年10月30日 星期日 10时30分46秒
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
double r;
const int maxn = (1 << 6);
struct Tree {
    DB L, R;
    Tree(DB l = 0, DB r = 0) {
	L = l; R = r;
    }
};


vector<Tree> tree[maxn];
double w[maxn];
double tw[maxn];
bool vis[maxn];

void Init() {
    scanf("%lf", &r);
    sf(n);
    rep(i, 0, maxn) tw[i] = 0.0, tree[i].clear();
    rep(i, 0, n) scanf("%lf", &w[i]);
    rep(subset, 0, maxn) {
	rep(i, 0, n) if(subset & (1 << i)) tw[subset] += w[i];
    }
    mem(vis, false);
}
void dfs(int subset) {
    if(vis[subset]) return ;
    vis[subset] = true;

    bool have_child = false;
    for(int left = (subset - 1) & subset; left; left = (left - 1) & subset) {

	have_child = true;
	int right = subset ^ left;
	DB d1 = tw[right] / tw[subset];
	DB d2 = tw[left] / tw[subset];

	dfs(left); dfs(right);
	
	for(int i = 0; i < tree[left].size(); i++) for(int j = 0; j < tree[right].size(); j++) {
	    Tree t;
	    t.L = Max(tree[left][i].L + d1, tree[right][j].L - d2);
	    t.R = Max(tree[left][i].R + d2, tree[right][j].R - d1);
	    if(t.L + t.R < r) tree[subset].push_back(t);
	}
    }
    if(!have_child) tree[subset].push_back(Tree());
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    dsD(t) {
	Init();
	int root = (1 << n) - 1;
	dfs(root);

	double ans = -1;
	for(int i = 0; i < tree[root].size(); i++) 
	    ans = Max(ans, tree[root][i].L + tree[root][i].R);
	printf("%.10lf\n", ans);
    }
    return 0;
}
