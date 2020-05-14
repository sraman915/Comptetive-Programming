#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 500005

int dp[2005][2005];

// dp(n, k) counts the number of partitions of the set {1, 2, …, n + 1} in which the element k + 1 is the largest element that can be alone in its set.
// dp[n][0] denotes the nth bell number


void pre(){
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        bell[i][0] = dp[i-1][i-1];
        for(int j = 1; j <= i; j++)
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
   }
}

int32_t main(){
sp;

    return 0;
}
