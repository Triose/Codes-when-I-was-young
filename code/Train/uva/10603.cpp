/*
 *
 *  Author : Triose
 *  Email  : Triose@163.com
 *  Update_time : 2016.9.11
 *
 */


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
const int maxn = 210;
bool vis[maxn][maxn];
int cap[3], D;
int Ans[maxn];
struct Node {
	int v[3], dv;
	Node(int a = 0, int b = 0, int c = 0, int dv_ = 0) {
		v[0] = a; v[1] = b; v[2] = c;
		dv = dv_;
	}
	friend bool operator < (Node u, Node v ) {
		return u.dv > v.dv;
	}
	void mark() {
		vis[v[0]][v[1]] = true;
	}
	bool valid() {
		return !vis[v[0]][v[1]];
	}
};


void Init() {
	mem(vis, false); mem(Ans, -1);
	Ans[0] = 0;
	rep(i, 0, 3) sf(cap[i]); sf(D);
}

void update_ans(const Node & node) {
	rep(i, 0, 3) {
		int d = node.v[i];
		if(Ans[d] < 0 || node.dv < Ans[d]) Ans[d] = node.dv;
	}
}

void solve() {
	priority_queue<Node> pq;
	pq.push(Node(0, 0, cap[2]));
	vis[0][0] = true;
	Node node;
	while(!pq.empty()) {
		node = pq.top(); pq.pop();
		// printf("%d %d %d %d\n", node.v[0], node.v[1], node.v[2], node.dv);
		update_ans(node);
		rep(i, 0, 3) rep(j, 0, 3) if(i != j) {
			if(node.v[i] == 0 || node.v[j] == cap[j]) continue;
			int amount = Min(cap[j], node.v[i] + node.v[j]) - node.v[j];
			Node u;
			memcpy(&u, &node, sizeof(node));
			u.dv = node.dv + amount;
			u.v[i] -= amount;
			u.v[j] += amount;
			if(u.valid()) {
				u.mark();
				pq.push(u);
			}
		}
	}
	while(D >= 0) {
		if(Ans[D] != -1) {
			pfd(Ans[D], D);
			return ;
		}
		D--;
	}
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