#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
template<class T>
T Min(T a, T b) {
    return a > b ? b : a;
}
template<class T>
T Max(T a, T b) {
    return a > b ? a : b;
}
#define N 100010
#define LL long long
LL a[N];
LL b[N];
int n,k;
int check(LL mid, int tmpk) {
    int tmp = tmpk;
    for(int i = 0; i < n; i++) {
	if(b[i] >= a[i] * mid) continue;
	tmp -= (a[i] * mid - b[i]);
	if(tmp < 0)
	    return -1;
    }
    tmp = tmpk; mid++;
    for(int i = 0; i < n; i++) {
	if(b[i] >= a[i] * mid) continue;
	tmp -= (a[i] * mid - b[i]);
	if(tmp < 0)
	    return 0;
    }
    return 1;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
#endif
    while(cin >> n >> k) {
//	cout << n << " " << k << endl;
	LL min_ans = INF;
	LL max_ans = -1;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	for(int i = 0; i < n; i++) {
	    cin >> b[i];
	    min_ans = Min(min_ans, b[i] / a[i]);
	    max_ans = Max(max_ans, ((b[i] + k) / a[i]) + 1);
	}
	//cout << check(132, k) << endl;
	//cout << max_ans << endl;
	if(check(max_ans, k) >= 0) {
	    cout << max_ans << endl;
	    continue;
	}
	LL mid_ans = (max_ans + min_ans) >> 1;
	while(min_ans < max_ans) {
	    mid_ans = (max_ans + min_ans) >> 1;
	    //cout << mid_ans << endl;
	    switch (check(mid_ans, k)) {
		case -1: max_ans = mid_ans; break;
		case 0: min_ans = max_ans; break;
		case 1: min_ans = mid_ans; break;
	    }
	}
	cout << mid_ans << endl;
    }
    return 0;
}
