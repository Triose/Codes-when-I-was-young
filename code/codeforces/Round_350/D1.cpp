#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define N 1010
template<class T> T Min(T a, T b) {return a > b ? b : a;}
int n,k;
int a[N];
int b[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
#endif
    while(cin >> n >> k) {
	int ans = 100000;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	for(int i = 0; i < n; i++) {
	    cin >> b[i];
	    ans = Min(ans, b[i] / a[i]);
	}
	
	int tmp = ans + 1;
	while(k >= 0) {
	    for(int i = 0; i < n; i++) {
		if(b[i] >= tmp * a[i])
		    continue;
		k -= (a[i] * tmp - b[i]);
		b[i] = a[i] * tmp;
	    }
	    if(k >= 0)
		ans = tmp;
	    tmp++;
	}
	
    	cout << ans << endl;
    }
    return 0;
}
