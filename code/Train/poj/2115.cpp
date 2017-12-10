#include<iostream>
#include<cstdlib>

using namespace std;
#define LL long long
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {
	x = 1; y = 0; return a;
    }
    LL d = exgcd(b, a % b, x, y);
    LL t = x; x = y; y = t - (a / b) * y;
    return d;
}

int main() {
    LL a, b, c, m, x, y;
    while(cin >> a >> b >> c >> m) {
	if(!m) break;
	m = 1 << m;
	LL g = exgcd(c, m, x, y);
	LL res = b - a;
	if(res % g) cout << "FOREVER\n";
	else {
	    LL ans = x * res / g;
	    LL r = m / g;
	    ans = (ans % r + r) % r;
	    cout << ans << endl;
	}
    }
    return 0;
}



