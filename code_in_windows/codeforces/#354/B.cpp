/*************************************************************************
    > File Name: B.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/5/26 星期四 上午 3:07:41
 ************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;
#define N 15
const double esp = 1e-5;
double tmp[N][N];
int n, t;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while(cin >> n >> t) {
		int tot = 0;
		memset(tmp, 0, sizeof(tmp));
		tmp[0][0] = t * 1.0;
		for(int i = 0; i < n - 1; i++) {
			for(int j = 0; j <= i; j++) {
				tmp[i + 1][j] += ((tmp[i][j] - 1 > 0 ? tmp[i][j] - 1 : 0)/ 2);
				tmp[i + 1][j + 1] += ((tmp[i][j] - 1 > 0 ? tmp[i][j] - 1 : 0)/ 2);
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= i; j++) {
				if(tmp[i][j] >= 1) tot++;
			}
		}
		/*
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= i; j++) {
				cout << tmp[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << tot << endl;
	}
	return 0;
}
