#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while(cin >> n) {
		printf("%d %d %d\n", 2, n, n);
		const int BASE = 'A';
		const int base = 'a';
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) putchar((i > 25 ? (base + (i % 26)) : (BASE + i)));
			putchar(10);
		}
		putchar(10);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) putchar((j > 25 ? (base + (j % 26)) : (BASE + j)));
			putchar(10);
		}
		putchar(10);
	}
	return 0;
}