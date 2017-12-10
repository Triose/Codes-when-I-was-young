/*************************************************************************
    > File Name: Calculator.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2017年01月11日 星期三 23时51分18秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int main() {
    double n, m;
    while(cin >> n >> m) {
	cout << -(m / n) * (log2(m / n)) << "\n";
    }
    return 0;
}
