#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
const int maxt = 205;

#define inf 0x3f3f3f3f

template<class T> T Min(T a, T b) { return a > b ? b : a; }

int dt[maxn]; // time of Station i -> i + 1
int n, T, m1, m2;
int d[maxn], e[maxn];
bool has_left[maxt][maxn], has_right[maxt][maxn];
int dp[maxt][maxn];


void Init() {
	memset(has_left, false, sizeof(has_left));
	memset(has_right, false, sizeof(has_right));
	memset(dp, inf, sizeof(dp));
	cin >> T;
	for(int i = 1; i < n; i++) cin >> dt[i];
	cin >> m1;
	for(int i = 1; i <= m1; i++) {
		cin >> d[i];
		int dT = d[i];
		for(int j = 1; j < n; j++) has_right[dT][j] = true, dT += dt[j];
	}
	cin >> m2;
	for(int i = 1; i <= m2; i++) {
		cin >> e[i];
		int dT = e[i];
		for(int j = n; j > 1; j--) has_left[dT][j] = true, dT += dt[j - 1];
	}
}

int Solve() {
	dp[T][n] = 0;
	for(int t = T - 1; t >= 0; t--) for(int s = 1; s <= n; s++) {
		dp[t][s] = dp[t + 1][s] + 1;
		if(has_left[t][s]) dp[t][s] = Min(dp[t][s], dp[t + e[s + 1]][s + 1]);
		if(has_right[t][s]) dp[t][s] = Min(dp[t][s], dp[t + d[s - 1]][s - 1]);
	}
	cout << inf << " " << dp[0][1] << endl;
	return dp[0][1] >= inf ? -1 : dp[0][1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int cas = 1;
	while(cin >> n) {
		Init();
		cout << "Case Number " << cas++ << ": ";
		int ans = Solve();
		if(ans == -1) cout << "impossible\n";
		else cout << ans << "\n";
	}
	return 0;
}