/*************************************************************************
    > File Name: 1004.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/5/14 星期六 上午 1:31:45
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
double n, m, r;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("Out.txt", "w", stdout);
#endif
	int _,t;
	sf(t);
	for(_ = 0; _ < t; _++) {
		scanf("%lf%lf%lf", &n,&m,&r);
		printf("Case #%d:\n", _ + 1);
		double dis = (m / 2) * tan((n - 2) * 90.0 / n);
		int flag = (int)(dis / r);
		if(flag % 2 == 1 || flag == 0) {
			pfs("I want to kiss you!");
		}
		else {
			pfs("Give me a kiss!");
		}

	}
	return 0;
}
