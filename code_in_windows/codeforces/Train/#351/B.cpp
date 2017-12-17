/*************************************************************************
    > File Name: B.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/5/12 星期四 下午 1:50:59
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
#define rep(i,a) for(int (i)=0; (i)<(a);(i)++)
#define mem(a,b) (memset((a),b,sizeof(a)))
#define LL long long
int n, m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int x,y;
	while(cin >> n >> m) {
		x = 0; y = INF;
		int tmpx, tmpy;
		rep(i,m) {
			cin >> tmpx >> tmpy;
			if(tmpx > tmpy) {
				tmpx ^= tmpy;
				tmpy ^= tmpx;
				tmpx ^= tmpy;
			}
			x = x < tmpx ? tmpx : x;
			y = y < tmpy ? y : tmpy;
		}
		if(m)
			cout << (y - x < 0 ? 0 : y - x) << endl;
		else
			cout << n - 1 << endl;
	}
	return 0;
}
