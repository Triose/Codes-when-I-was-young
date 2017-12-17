/*************************************************************************
    > File Name: 672A.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/5/16 星期一 上午 9:33:06
 ************************************************************************/


#include<iostream>
using namespace std;
int n;
int main() {
	while(cin >> n) {
		int ans = 0;
		if(n < 10 && n > 0) 
			cout << n << endl;
		else if(n < 190 && n > 9) {
			n -= 9;
			ans = 10 + n / 2;
			cout << (n % 2 != 0 ? (ans / 10) : (ans % 10)) << endl;
		}
		else {
			n -= 190;
			ans = 100 + n / 3;
			switch (n % 3) {
				case 0: cout << n / 100 << endl; break;
				case 1: cout << (n % 100) / 10 << endl; break;
				case 2: cout << n % 10 << endl; break;
			}
		}
	}
	return 0;
}
