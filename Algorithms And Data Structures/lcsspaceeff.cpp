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
    string a,b;
    cin>>a>>b;
    int c, n = a.size(), m = b.size();
    int dp[2][m+1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i){
        c = i&1;
        for(int j = 1; j <= m; ++j){
            if(a[i-1] == b[j-1])
                dp[c][j] = dp[1-c][j-1] + 1;
            else
                dp[c][j] = max(dp[1-c][j], dp[c][j-1]);
        }
    }
    cout<<dp[c][m];

    return 0;
}
