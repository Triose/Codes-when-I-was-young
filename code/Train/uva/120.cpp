#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;
int n;
int a[maxn];
string line;


void Init() {	//[1, n]
	n = 0;
	stringstream ss(line);
	int tmp;
	while(ss >> tmp) a[++n] = tmp;
}

void Check() {
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	putchar(10);
}

void Swap_arr(int pos) {
	int i = 1, j = pos;
	while(i < j) {
		a[i] ^= a[j];
		a[j] ^= a[i];
		a[i] ^= a[j];
		i++; j--;
	}
}

void Solve() {
	cout << line << "\n";
	for(int j = n; j > 0; j--) {
		int idx = max_element(a + 1, a + 1 + j) - a;
		if(a[idx] > a[j]) {
			if(idx != 1) printf("%d ", (n - idx + 1));
			printf("%d ", (n - j + 1));	
			Swap_arr(idx); Swap_arr(j);
		}
	}
	printf("0\n");
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while(getline(cin, line)) {
		Init();
		Solve();
		// Check();
	}
	return 0;
}