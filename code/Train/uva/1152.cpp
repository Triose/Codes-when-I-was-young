#include <bits/stdc++.h>
using namespace std;

void getInt(int& p) {  
	char ch;
	p = 0;
	bool neg = false;
    ch = getchar();
    if(ch == '-') {
    	neg = true;
    	while((ch = getchar()) > '9' || ch < '0');
    }
    do {
    	p = p * 10 + ch - '0';
    }while((ch = getchar()) <= '9' && ch >= '0');
    p = (neg ? -p : p);
}  

const int maxn = 40010;
int n;
map<int, int> mpa, mpb;
int a[maxn], b[maxn], c[maxn], d[maxn];

void Init() {
	mpa.clear(); mpb.clear();
	cin >> n;
	for(int i = 0; i < n; i++) {
		//cin >> a[i] >> b[i] >> c[i] >> d[i];
		getInt(a[i]); getInt(b[i]); getInt(c[i]); getInt(d[i]);
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
		mpa[a[i] + b[j]]++;
		mpb[c[i] + d[j]]++;
	}
}

#define LL long long
LL Solve() {
	LL ret = 0;
	for(map<int, int>::iterator it = mpa.begin(); it != mpa.end(); it++) {
		if(mpb.count(-(it->first))) ret += (mpa[it->first] * mpb[-(it->first)]);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		Init();
		for(int i = 0; i < n; i++) cout << a[i] << "\n";
		// cout << Solve() << "\n\n";
	}
	return 0;
}
