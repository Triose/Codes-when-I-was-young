/*
ID: triose1
LANG: C++
TASK: gift1
*/
/*
ID: triose1
LANG: C++
TASK: gift1
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<map>
#include<set>
using namespace std;
//#define ONLINE_JUDGE
#define eps 1e-8
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define rep(i,a) for((i)=0; i<(a);(i)++)
#define mem(a,b) (memset((a),b,sizeof(a)))
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfs(a) scanf("%s",a)
#define pf(a) printf("%d\n",a)
#define pfs(a) printf("%s\n",a)
#define pfI(a) printf("%I64d\n",a)
#define LL __int64
const double PI = acos(-1.0);
const double E = exp(1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b)*b; }
template<class T> inline T Min(T a, T b) { return a<b ? a : b; }
template<class T> inline T Max(T a, T b) { return a>b ? a : b; }
int n, m;
map<string, int> fri;
map<string, int>::iterator it;
int main() {
#ifndef ONLINE_JUDGE
//    ifstream fin("gift1.in");;
//    ofstream fout("gift1.out");
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
#endif
    if(!fri.empty())
        fri.clear();
    int money, person;
    string giver, gived;
    cin >> n;
    string tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        fri[tmp] = 0;
    }
    while(cin >> giver) {
    	cin >> money >> person;
    	fri[giver] -= money % person;
    	for(int i = 0; i < person; i++) {
    		cin >> gived;
    		fri[gived] += (money / person);
    	}
    }
    it = fri.begin();
    while(it != fri.end()) {
    	cout << it->first << " " << it->second << endl;
    	it++;
    }
    return 0;
}

