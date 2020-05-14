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

int32_t main(){
sp;
    int limit, n;
    cin>>limit>>n;
    int w[n + 1], a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin>>w[i]>>a[i];
    int dp[n + 1][limit + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i < n + 1; ++i)
        for(int j = 1; j < limit + 1; ++j){
            if(w[i] <= j)
                dp[i][j] = max(a[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    cout<<dp[n][limit];
    return 0;
}
