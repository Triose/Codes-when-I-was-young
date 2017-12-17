/*************************************************************************
    > File Name: pro2.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/4/16 星期六 下午 1:29:23
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
#include<map>
#include<set>
using namespace std;
//#define ONLINE_JUDGE
#define eps 1e-8
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define rep(i,a) for((i)=0; i<(a);(i)++)
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
#define LL __int64
const double PI = acos(-1.0);
const double E = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b)*b; }
template<class T> inline T Min(T a, T b) { return a<b ? a : b; }
template<class T> inline T Max(T a, T b) { return a>b ? a : b; }
int n, m;
#define N 20
struct Person {
	char name[N];
	int team;
	int score;
};
#define M 10010
struct Regions{
	Person first;
	Person second;
	Person third;
};
Regions r[M];
Person tmp;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("Out.txt", "w", stdout);
#endif
	while(~sfd(n, m)) {
		for(int i = 0; i <= m; i++) {
			r[i].first.score = -1;
			r[i].second.score = -1;
			r[i].third.score = -1;
		}
		for(int i = 0; i < n; i++) {
			scanf("%s%d%d", tmp.name, &tmp.team, &tmp.score);
			if(tmp.score > r[tmp.team].first.score) {
				strcpy(r[tmp.team].third.name, r[tmp.team].second.name);
				r[tmp.team].third.score = r[tmp.team].second.score;
				strcpy(r[tmp.team].second.name, r[tmp.team].first.name);
				r[tmp.team].second.score = r[tmp.team].first.score;
				strcpy(r[tmp.team].first.name, tmp.name);
				r[tmp.team].first.score = tmp.score;
			}
			else if(tmp.score > r[tmp.team].second.score) {
				strcpy(r[tmp.team].third.name, r[tmp.team].second.name);
				r[tmp.team].third.score = r[tmp.team].second.score;
				strcpy(r[tmp.team].second.name, tmp.name);
				r[tmp.team].second.score = tmp.score;
			}
			else if(tmp.score > r[tmp.team].third.score) {
				strcpy(r[tmp.team].third.name, tmp.name);
				r[tmp.team].third.score = tmp.score;
			}
		}
		for(int i = 1; i <= m; i++) {
			if(r[i].second.score == r[i].third.score)
				pfs("?");
			else {
				printf("%s %s\n", r[i].first.name, r[i].second.name);
			}
		}
	}
	return 0;
}


