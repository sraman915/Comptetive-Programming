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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int dp[n+1], last[256];
        dp[0] = 1;
        memset(last, -1, sizeof(last));
        for(int i = 1; i <= n; ++i){
            dp[i] = 2LL * dp[i-1];
            if(dp[i] >= mod)
                dp[i] %= mod;
            if(last[s[i - 1]] != -1)
                dp[i] = (dp[i] - dp[last[s[i - 1]] - 1]);
            if(dp[i] < 0)
                dp[i] += mod;
            last[s[i - 1]] = i;
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}
