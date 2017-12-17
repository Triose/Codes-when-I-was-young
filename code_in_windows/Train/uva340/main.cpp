/*************************************************************************
    > File Name: main.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/4/13 星期三 下午 9:58:17
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
#define LL __int64
const double PI = acos(-1.0);
const double E = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b)*b; }
template<class T> inline T Min(T a, T b) { return a<b ? a : b; }
template<class T> inline T Max(T a, T b) { return a>b ? a : b; }
int n, m;
#define N 1010
int souce[N];
int aim[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("Out.txt", "w", stdout);
#endif
	int k = 0;
	while(sf(n) && n) {
		for(int i = 0; i < n; i++) {
			sf(souce[i]);
		}
		printf("Game %d:\n", ++k);
		for(; ;) {
			int a = 0, b = 0;
			for(int i = 0; i < n; i++) {
				sf(aim[i]);
				if(aim[i] == souce[i])
					a++;
			}
			if(!aim[0])
				break;
			int tmps = 0, tmpa = 0;
			for(int i = 1; i < 10; i++) {
				for(int j = 0; j < n; j++) {
					if(souce[j] == i)
						tmps++;
					if(aim[j] == i)
						tmpa++;
				}
				b += Min(tmps, tmpa);
				tmps = 0;
				tmpa = 0;
			//	pf(b);
			}
			printf("    (%d,%d)\n",a,b - a);
		}
	}
	return 0;
}
