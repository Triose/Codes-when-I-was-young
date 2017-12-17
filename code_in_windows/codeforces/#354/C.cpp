/*************************************************************************
    > File Name: C.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/5/28 星期六 下午 5:15:12
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define N 100010
char str[N];
int a[N], b[N];
int n,m;
int max(int u, int v) {
	return u > v ? u : v;
}
int binary(int s, int e, int flag) {
	int low = s + m, high = e;
	if(low > n) low = n;
	int *tmp = (flag ? a : b);
	while(low < high) {
		int mid = (low + high) >> 1;
		if(tmp[mid] - tmp[s - 1] <= m) {
			if(tmp[mid + 1] - tmp[s - 1] > m) {
				return mid - s + 1;
			}
			low = mid + 1;
		}
		else {
			if(tmp[mid - 1] - tmp[s - 1] == m) {
				return mid - s;
			}
			high = mid - 1;
		}
	}
	return low - s + 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while(~scanf("%d%d",&n,&m)) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%s", str + 1);
		int lena = 0;
		int lenb = 0;
		for(int i = 0; i <= n; i++) {
			a[i] = (str[i] == 'a' ? a[i - 1] + 1 : a[i - 1]);
			b[i] = (str[i] == 'b' ? b[i - 1] + 1 : b[i - 1]);
		}
		for(int i = 1; i <= n; i++) {
			lena = max(lena, binary(i, n, 0));
			lenb = max(lenb, binary(i, n, 1));
		}
		printf("%d\n", max(lena, lenb));

	}
	return 0;
}
