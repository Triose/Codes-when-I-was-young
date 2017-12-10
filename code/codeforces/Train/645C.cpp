/*************************************************************************
    > File Name: 645C.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年06月08日 星期三 21时21分39秒
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
#include<time.h>
#include<map>
#include<set>
using namespace std;
//#define ONLINE_JUDGE
#define eps 1e-8
#define INF 0x7fffffff
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define inf 0x3f3f3f3f
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define repe(i,a,b) for(int i = (a); i <= (b); ++i)
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
#define DB double
const double PI = acos(-1.0);
const double E = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b)*b; }
template<class T> inline T Min(T a, T b) { return a<b ? a : b; }
template<class T> inline T Max(T a, T b) { return a>b ? a : b; }
int n, m;
#define N 100010
int a[N];
char str[N];
int minn;

bool check(int pos, int len) {
    int left = Max(1, pos - len);
    int right = Min(n, pos + len);
    return a[right] - a[left - 1] >= m;
}

void brain_search(int th) {
    int low = 1, high = n;
    while(low <= high) {
	int mid = (low + high) >> 1;
	if(check(th, mid)) {
	    minn = Min(minn, mid);
	    high = mid - 1;
	}
	else {
	    low = mid + 1;
	}
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    while(~sfd(n,m)) {
	m++;
	sfs(str + 1);
	a[0] = 0;
	repe(i,1,n) a[i] = (1 - (str[i] - '0')) + a[i - 1];
	minn = INF;
	repe(i,1,n) {
	    if(str[i] == '1') continue;
	    brain_search(i);
	}
	pf(minn);
    }
    return 0;
}
