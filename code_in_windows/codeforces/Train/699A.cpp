/*************************************************************************
    > File Name: 699A.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/5/7 星期六 下午 4:40:15
 ************************************************************************/
#include<iostream>
using namespace std;
int n;
int main() {
	while(cin >> n) {
		int ans = 0;
		while(n) {
			if(n >= 1) {
				n--;
				ans++;
			}
			if(n >= 2) {
				n -= 2;
				ans++;
			}
			else
				break;
		}
		cout << ans << endl;
	}
	return 0;
}
