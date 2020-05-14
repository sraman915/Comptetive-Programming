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
    cin>>s>>p;
    int n = s.size(), m = p.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(s[i - 1] == p[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

    int ans = 0,l = -1,r = -2;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j){
            if(dp[i][j] > ans){
                ans = dp[i][j];
                l = i;
                r = l + ans - 1;
            }
    }
    if(l != -1)
        cout<<s.substr(l - ans, ans);
    return 0;
}
