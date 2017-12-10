/*************************************************************************
    > File Name: 506.cpp
    > Author: Triose
    > Mail: Triose@163.com 
    > Created Time: 2016年09月25日 星期日 12时27分02秒
 ************************************************************************/

//#include<bits/stdc++.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string.h>
#include <iterator>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//#define ONLINE_JUDGE

#define eps 1e-8
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define enter putchar(10)

#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define per(i,a,b) for(int i = (a); i >= (b); --i)
#define repe(i,a,b) for(int i = (a); i <= (b); ++i)
#define ECH(it, A) for (typeof(A.begin()) it=A.begin(); it != A.end(); ++it)

#define PR(a,b) pair<a,b>
#define slen(str) strlen(str)
#define ds(t) int t; sf(t)
#define Down(t) while(t--)
#define dc(t) int t; cin >> t;
#define dsD(t) ds(t); Down(t)
#define dcD(t) dc(t); Down(t)
#define ALL(A) A.begin(), A.end()
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scpy(str1, str2) strcpy(str1, str2)
#define sfs(a) scanf("%s",a)
#define pf(a) printf("%d\n",a)
#define pfd(a,b) printf("%d %d\n",a,b)
#define pfP(a) printf("%d %d\n",a.fi,a.se)
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%I64d\n",a)
#define mem(a,b) memset((a),b,sizeof(a))

#define fi first
#define se second
#define LL long long
#define DB double
#define isws ios::sync_with_stdio(false)
const double PI = acos(-1.0);
const double E = exp(1.0);

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }

int n, m;
const int maxn = 10010;

int status[maxn];
map<string, int> IDtable;
vector<string> IDcache;
vector<int> depend[maxn],depended[maxn];
vector<int> installed;
string line, name1, name2;
string order;

int ID(string name) {
    if(IDtable.count(name)) return IDtable[name];
    IDcache.push_back(name);
    return IDtable[name] = IDcache.size() - 1;
}

void Link(int id1, int id2) {
    depend[id1].push_back(id2);
    depended[id2].push_back(id1);
}

void install(int id, int tp) {
    if(!status[id]) {
	for(vector<int>::iterator it = depend[id].begin(); it != depend[id].end(); it++) {
	    if(!status[*it]) install(*it, 2);
	}
	cout << "   Installing " << IDcache[id] << "\n";
        installed.push_back(id);
	status[id] = tp;
    }
}

bool needed(int id) {
    for(vector<int>::iterator it = depended[id].begin(); it != depended[id].end(); it++) {
	if(status[*it]) return true;
    }
    return false;
}

void remove(int id, int tp) {
    if((tp == 1 || status[id] == 2) && !needed(id)) {
	status[id] = 0;
	installed.erase(remove(installed.begin(), installed.end(), id), installed.end());
	cout << "   Removing " << IDcache[id] << "\n";
	for(vector<int>::iterator it = depend[id].begin(); it != depend[id].end(); it++) remove(*it, 2);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
//  freopen("Out.txt", "w", stdout);
#endif
    isws;
    IDtable.clear();IDcache.clear();
    rep(i, 0, maxn) depend[i].clear(), depended[i].clear();
    installed.clear(); mem(status, 0);
    while(getline(cin, line)) {
	cout << line << "\n";
	if(line == "END") break;
	stringstream ss(line);
	ss >> order;
	if(order == "DEPEND") {
	    ss >> name1;
	    int id1 = ID(name1), id2;
	    while(ss >> name2) {
		id2 = ID(name2);
		Link(id1, id2);
	    }
	}
	else if(order == "INSTALL") {
	    ss >> name1; int id = ID(name1);
	    if(status[id] != 0) {
		cout << "   " << name1 << " is already installed.\n";
	    }
	    else {
		install(id, 1);
	    }
	}
	else if(order == "REMOVE") {
	    ss >> name1; int id = ID(name1);
	    if(status[id] == 0) {
		cout << "   " << name1 << " is not installed.\n";
	    }
	    else if(needed(id)) {
		cout << "   " << name1 << " is still needed.\n";
	    }
	    else {
		remove(id, 1);
	    }
	}
	else if(order == "LIST") {
	    for(vector<int>::iterator it = installed.begin(); it != installed.end(); it++) 
		cout << "   " << IDcache[*it] << "\n";
	}
    }
    return 0;
}
