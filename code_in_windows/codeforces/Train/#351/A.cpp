/*************************************************************************
    > File Name: A.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/5/12 星期四 下午 1:32:50
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 100
#define rep(i,n) for(int (i) = 0; (i) < n; (i)++)
int n;
int a[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin >> n) {
		rep(i, n) cin >> a[i];
		a[n] = 90;
		int ans = 0;
		int tmp = 0;
		rep(i, n + 1) {
			if(a[i] - tmp > 15){
				ans += 15; break;
			}
			else ans += (a[i] - tmp);
			tmp = a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
