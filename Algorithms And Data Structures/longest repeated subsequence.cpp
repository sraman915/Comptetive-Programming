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
    string s, p;
    cin>>s;
    int n = s.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(s[i - 1] == s[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);

    int ans = 0, l = -1, r = -1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(dp[i][j] > ans){
                ans = dp[i][j];
                l = i-ans;
            }
    ans = dp[n][n];
    cout<<ans;
    return 0;
}
