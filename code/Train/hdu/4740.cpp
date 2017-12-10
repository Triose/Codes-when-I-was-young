#include <bits/stdc++.h>
using namespace std;


const int maxn = 1010;
const int dir[] = {0, 1, 2, 3};
const int nxt[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
pair<int, int> pathd[maxn * maxn], patht[maxn * maxn];
bool visd[maxn][maxn], vist[maxn][maxn];
int rx, ry, rd, tx, ty, td;
int cntd, cntt;
int n;

int turn(int now, char ch) {
	return ch == 'l' ? (now + 3) % 4 : (now + 1) % 4;
}

struct Node {
	int x, y, direction;
	char tn;
	Node(int x_ = 0, int y_ = 0, int d_ = 0, char ch_ = 'l') {
		x = x_; y = y_; direction = d_;
		tn = ch_;
	}
	void mark() {
		tn == 'r' ? visd[x][y] = true : vist[x][y] = true;
	}
	bool can_go() {
		int x_ = x + nxt[direction][0];
		int y_ = y + nxt[direction][1];
		if(x_ < n && x_ >= 0 && y_ < n && y_ >= 0) {
			if(tn == 'r' && !visd[x_][y_]) return true;
			else if(!vist[x_][y_]) return true;
		}
		int newdir = turn(direction, tn);
		x_ = x + nxt[newdir][0];
		y_ = y + nxt[newdir][1];
		if(x_ < n && x_ >= 0 && y_ < n && y_ >= 0) {
			if(tn == 'r') return !visd[x_][y_];
			else return !vist[x_][y_];
		}
		return false;
	}
	Node go() {
		int x_ = x + nxt[direction][0];
		int y_ = y + nxt[direction][1];
		if(x_ < 0 || x_ >= n || y_ < 0 || y_ >= n || (tn == 'r' && visd[x_][y_]) || (tn == 'l' && vist[x_][y_])) {
			direction = turn(direction, tn);
			x_ = x + nxt[direction][0];
			y_ = y + nxt[direction][1];
		}
		return Node(x_, y_, direction, tn);
	}
};

void work() {
	cntd = 1; cntt = 1;
	memset(visd, false, sizeof(visd));
	memset(vist, false, sizeof(vist));
	cin >> rx >> ry >> rd;
	cin >> tx >> ty >> td;
	Node donkey(rx, ry, rd, 'r'), tiger(tx, ty, td, 'l');
	pathd[0].first = rx; pathd[0].second = ry;
	patht[0].first = tx; patht[0].second = ty;
	while(donkey.can_go() || tiger.can_go()) {
		if(donkey.can_go()) {
			donkey = donkey.go();
			pathd[cntd].first = donkey.x;
			pathd[cntd].second = donkey.y;
			cntd++;
		}
		else {
			pathd[cntd] = pathd[cntd - 1];
			cntd++;
		}
		if(tiger.can_go()) {
			tiger = tiger.go();
			patht[cntt].first = tiger.x;
			patht[cntt].second = tiger.y;
			cntt++;
		}
		else {
			patht[cntt] = patht[cntt - 1];
			cntt++;
		}
	}
}
void print() {
	// for(int i = 0; i < cntd; i++) {
	// 	if(pathd[i].first == patht[i].first && pathd[i].second == patht[i].second) {
	// 		cout << pathd[i].first << " " << patht[i].second << "\n";
	// 		return ;
	// 	}
	// }
	// cout << "-1\n";
	cout << "cnt:\n"; 
	cout << cntd << " " << cntt << "\n";
	for(int i = 0; i < cntd; i++) {
		cout << pathd[i].first << " " << pathd[i].second << "\n";
		cout << patht[i].first << " " << patht[i].second << "\n\n";
	}
	cout << "\n\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while(cin >> n && n) {
		work();
		print();
	}
	return 0;
}