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
#define maxn 15
#define maxl 105
char ptn[maxn][maxl];


#define childsCount 26
struct Elmt { //Element of trie tree.
    Elmt * pv, fail;
    char info;
    bool isEnd;
    Elmt * child[childsCount];
    Elmt(Elmt * pv_ = NULL, char info_ = '0', bool isEnd_ = false) {
	pv = pv_;
	fail = NULL;
	info = info_;
	isEnd = isEnd_;
	mem(child, NULL);
    }
    Elmt * getPv() {
	return pv;
    }
    void setPv(Elmt * eptr) {
	pv = eptr;
    }
    void setFail(Elmt * eptr) {
	fail = eptr;
    }
    Elmt * getFail() {
	return fail;
    }
    
};

struct ACAutoMechine {
    Elmt root;	    //Trie tree
    void Init() {
	root.pv = NULL; root.info = '0'; root.isEnd = false;
	root.fail = NULL;

    }
};





int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    
    return 0;
}
