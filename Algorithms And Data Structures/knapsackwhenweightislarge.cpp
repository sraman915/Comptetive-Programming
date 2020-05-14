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

int dp[101][mxn];
int w[101], a[101];
int n;
int W;

int solve(int id, int profit){
    if(profit == 0)
        return 0;
    if(id == n + 1 || profit < 0)
        return 1e15;
    auto &ans = dp[id][profit];
    if(ans != -1)
        return ans;
    ans = min(solve(id + 1, profit), w[id] + solve(id + 1, profit - a[id]));
    return ans;
}


int32_t main(){
sp;
    cin>>n>>W;
    for(int i = 1; i <= n; ++i)
        cin>>w[i]>>a[i];
    memset(dp, -1, sizeof dp);
    int ans=0;
    for(int i = 1; i <= 100000; ++i){
        int temp = solve(1, i);
        if(temp <= W)
            ans = i;
    }
    cout<<ans;
    return 0;
}
