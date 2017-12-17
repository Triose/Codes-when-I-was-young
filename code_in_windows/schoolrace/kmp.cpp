/*************************************************************************
    > File Name: kmp.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/4/19 星期二 下午 1:00:20
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
#define N 110
char str[N][N];
char aim[N];
int table[N];
int len;
int z,x;
void tolow(char * s) {
	for(int i = 0; i < m; i++) {
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
}
void get_table() {
	len = strlen(aim);
	table[0] = 0; table[1] = 0;
	for(int i = 1; i < len; i++) {
		int j = table[i];
		while(j && aim[i] != aim[j]) j = table[i];
		table[i + 1] = aim[i] == aim[j] ? j + 1 : 0;
	}
}
bool jud() {
	int i, j, k;
	i = 0; j = 0; k = 0;
	while(i < n && k < len) {
		while(k && str[i][j] != aim[k]) k = table[k];
		if(aim[k] == str[i][j]) k++;
		if(k == len) return true;
		j++;
		if(j == m) {
			i++;
			j = 0;
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("Out.txt", "w", stdout);
#endif
	while(~sfd(n,m)) {
		for(int i = 0; i < n; i++) {
			sfs(str[i]);
			tolow(str[i]);
		}
		sfs(aim);
		tolow(aim);
		get_table();
		if(jud()) {
			pfs("YES");
		}
		else {
			pfs("NO");
		}
	}
	return 0;
}

