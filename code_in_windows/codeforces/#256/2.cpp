/*************************************************************************
    > File Name: 2.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/4/25 星期一 下午 1:40:31
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
int index1, index2;
int len1, len2;
#define N 110
char str1[N];
char str2[N];
int coun[30];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
//	freopen("Out.txt", "w", stdout);
#endif
	while(~sfs(str1)) {
		sfs(str2);
		index1 = false;
		index2 = false;
		len1 = strlen(str1);
		len2 = strlen(str2);
		index1 = (len1 == len2 ? false : true);
		mem(coun, 0);
		for(int i = 0; i < len1; i++) {
			coun[str1[i] - 'a']++;
		}
		int j = 0;
		for(j = 0; j < len2; j++) {
			coun[str2[j] - 'a']--;
			if(coun[str2[j] - 'a'] < 0) {
				break;
			}
		}
		if(j == len2) {
			int i,k;
			for(i = 0, k = 0; i < len1 && k < len2;) {
				if(str1[i] == str2[k]) {
					i++;k++;
				}
				else {
					i++;
				}
			}
			if(k != len2) {
				index2 = true;
			}
		}
		else {
			index1 = false;
			index2 = false;
		}
		if(index1 && index2) {
			pfs("both");
		}
		else if(index1 && !index2) {
			pfs("automaton");
		}
		else if(!index1 && index2) {
			pfs("array");
		}
		else {
			pfs("need tree");
		}
		//pfd(index1, index2);
	}
	return 0;
}

