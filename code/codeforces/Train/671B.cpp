/*************************************************************************
    > File Name: 671B.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年06月02日 星期四 09时32分29秒
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
#define LL long long
const double PI = acos(-1.0);
const double E = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b)*b; }
template<class T> inline T Min(T a, T b) { return a<b ? a : b; }
template<class T> inline T Max(T a, T b) { return a>b ? a : b; }
template<class T> T Abss(T a, T b) { return a - b > 0 ? a - b : b - a;}
int n, m;
#define N 500010
int a[N];
int maxx, minn;
LL sum;
int get_max() {
    int low = (sum % n == 0 ? sum / n : sum / n + 1), high = maxx;
    int mid;
	LL count;
    int ans = 0;
    while(low <= high) {
	mid = (low + high) >> 1;
	count = 0;
	rep(i, n)  count += Max(0, a[i] - mid);
	if(count <= m) {
	    ans = mid;
	    high = mid - 1;
	}
	else {
	    low = mid + 1;
	}
    }
    return ans;
}
int get_min() {
    int low = minn, high = sum / n;
    int mid;
	LL count;
    int ans = 0;
    while(low <= high) {
	mid = (low + high) >> 1;
	count = 0;
	rep(i, n) count += Max(0, mid - a[i]);
	/*
	cout << "high:" << high << endl;
	cout << "mid:" << mid << endl;
	cout << "low:" << low << endl;
	*/
	if(count <= m) {
	    ans = mid;
	    low = mid + 1;
	}
	else {
	    high = mid - 1;
	}
    }
//    cout << "ans = " << ans << endl;
    return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfd(n,m)) {
	maxx = -1;
	minn = INF;
	sum = 0;
	rep(i, n) {
	    sf(a[i]);
	    sum += a[i];
	    maxx = Max(maxx, a[i]);
	    minn = Min(minn, a[i]);
	}
/*	
	cout << sum << endl;	
	cout << "max:" << get_max() << endl;
	cout << "min:" << get_min() << endl;
*/	
	pf(get_max() - get_min());
    }
    return 0;
}
