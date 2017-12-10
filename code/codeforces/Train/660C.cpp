/*************************************************************************
    > File Name: 660C.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年06月05日 星期日 12时46分49秒
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
#define rep(i,a) for(int (i)=0; i<(a);(i)++)
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
#define N 300010
int a[N];
int s, e;
int max_len;
void brain_serach(int th) {
    int low = m + th - 1;
    int high = n;
    while(low <= high) {
	int mid = (low + high) >> 1;
	if(a[mid] - a[th - 1] <= m) {
	    if(mid - th + 1 > max_len) {
		//printf("%d %d %d\n\n", th, mid, max_len);
		max_len = mid - th + 1;
		s = th; e = mid;
	    }
	    low = mid + 1;
	}
	else {
	    high = mid - 1;
	}
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfd(n,m)) {
	mem(a,0);
	max_len = 0;
	rep(i, n) {
	    sf(a[i + 1]);
	    a[i + 1] = (1 - a[i + 1]) + a[i];
	}
	for(int i = 1; i <= n; i++) {
	    brain_serach(i);
	}
	pf(max_len);
	for(int i = 1; i <= n; i++) {
	    if(i <= e && i >= s) {
		printf("1%c", i == n ? '\n' : ' ');
		continue;
	    }
	    printf("%d%c", 1 - (a[i] - a[i - 1]), i == n ? '\n' : ' ');
	}
    }
    return 0;
}
