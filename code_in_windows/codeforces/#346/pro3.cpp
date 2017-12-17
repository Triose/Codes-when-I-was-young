/*************************************************************************
    > File Name: pro3.cpp
    > Author: Triose
    > Mail: Triose@163.com
    > Created Time: 2016/4/16 星期六 下午 2:29:16
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
#define N 100010
int has[N];
int buy[N];
int sum;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("Out.txt", "w", stdout);
#endif
	while(~sfd(n , m)) {
		sum = 0;
		for(int i = 0; i < n; i++)
			sf(has[i]);
		has[n] = INF;
		sort(has, has + n);
		for(int i = 1, j = 0, k = 0; m >= 0; i++) {
			if(has[j] > i) {
				m -= i;
				if(m >= 0) {
					sum++;
					buy[k++] = i;
				}
			}
			else if(has[j] == i) {
				while(j < n && has[j] <= i) {
					j++;
				}
			}
		}
		pf(sum);
		for(int i = 0; i < sum; i++) {
			printf("%d%c", buy[i], i == sum - 1 ? '\n' : ' ');
		}
	}
	return 0;
}

