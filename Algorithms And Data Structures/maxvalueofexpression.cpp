#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"
using namespace std;
#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
int n;
LL a[100010];
char op[100010];
LL dp[100010][3];
void init() {
}
void input() {
	cin >> n;
	REP(i, n) {
		cin >> a[i];
		if (i < n-1) cin >> op[i+1];
	}
}
void solve() {
	REP(i, 100010) REP(j, 3) dp[i][j] = -1e15;
	dp[0][0] = a[0];
	FOR(i, 1, n){
		if(op[i] == '+'){
			dp[i][0] = max(
				dp[i-1][0]+a[i],
				dp[i-1][1]+a[i]);
			dp[i][1] = dp[i-1][1]-a[i];
			dp[i][2] = dp[i-1][2]+a[i];
		}
		else{
			dp[i][1] = dp[i-1][0]-a[i];
			dp[i][2] = max(
				dp[i-1][1]+a[i],
				dp[i-1][2]+a[i]
				);
		}
	}
	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
}
int main() {
	freopen("input01.txt","r",stdin);
	freopen("output01.txt","w",stdout);
	init();
    input();
    solve();
	return 0;
}
