/*************************************************************************
    > File Name: B1.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016/5/28 星期六 下午 10:54:11
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#define N 100010
char str[N];
int suma[N], sumb[N];
int n,m;
int Max(int x, int y) {
	return x > y ? x : y;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while(~scanf("%d%d", &n, &m)) {
		scanf("%s", str + 1);
		int len1 = 0, len2 = 0;
		memset(suma, 0, sizeof(suma));
		memset(sumb, 0, sizeof(sumb));
		for(int i = 1; i <= n; i++) {
			suma[i] = suma[i - 1] + (str[i] == 'a');
			sumb[i] = sumb[i - 1] + (str[i] == 'b');
		}
		int poss = 1, pose = n;
		for(; poss <= n; poss++) {	// for a
			pose = n;
			while(sumb[pose] - sumb[poss - 1] > m) {
				pose--;
			}
			len1 = Max(len1, pose - poss + 1);
		}
		poss = 1; pose = n;
		for(; poss <= n; poss++) {	// for b
			pose = n;
			while(suma[pose] - suma[poss - 1] > m) {
				pose--;
			}
			len2 = Max(len2, pose - poss + 1);
		}
		printf("%d\n", Max(len1, len2));
	}
	return 0;
}
