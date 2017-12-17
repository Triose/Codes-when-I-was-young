/*************************************************************************
    > File Name: uva1010.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/4/1 星期五 下午 11:18:58
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
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%I64d\n",a)
#define pfd(a,b) printf("%d %d\n",a,b)
#define LL __int64
#define enter putchar(10)
const double PI = acos(-1.0);
const double E = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b)*b; }
template<class T> inline T Min(T a, T b) { return a<b ? a : b; }
template<class T> inline T Max(T a, T b) { return a>b ? a : b; }
int n, m;
#define N 60
char pic[N][N];
bool mark[N][N];
char aim[N];
bool ind;
int len;
void dfs(int x, int y, int pos) {
    if(pos == len) {
        ind = true;
        return ;
    }
    if(ind)
        return ;
    for(int i = -1; i < 2 && !ind; i++) {
        for(int j = -1; j < 2 && !ind; j++) {
            if(x + i < 0 || x + i >= n || y + j < 0 || y + j >= m)
                continue;
            if(mark[x + i][y + j]) 
                continue;
            if(pic[x + i][y + j] == aim[pos]) {
                mark[x + i][y + j] = true;
                dfs(x + i, y + j, pos + 1);
                mark[x + i][y + j] = false;
            }
        }
    }
    return ;
}
void tolow(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return ;
}
void solve() {
    tolow(aim);
    len = strlen(aim);
    mem(mark, false);
    ind = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(pic[i][j] == aim[0]) {
                mark[i][j] = true;
                dfs(i, j, 1);
                if(ind) {
                    pfd(++i, ++j);
                    return ;
                }
                mark[i][j] = false;
            }
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("Out.txt", "w", stdout);
#endif
    int _;
    sf(_);
    int q;
    while(_--) {
        sfd(n,m);
        for(int i = 0; i < n; i++) {
            sfs(pic[i]);
            tolow(pic[i]);
        }
        sf(q);
        while(q--) {
            sfs(aim);
            solve();
        }
        enter;
    }
	return 0;
}

