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
vector<pi> g[50004];
int n,m;
int dp[50004][101];
int ans=0;

void dfs(int x=1,int par=0){
    dp[x][0]=1;
    for(auto &it:g[x]){
        if(it.f==par)
        continue;
        dfs(it.f,x);
        for(int j=0; j<=m-it.s; ++j)
            ans=(ans+1LL*dp[it.f][j]*dp[x][m-it.s-j])%mod;
        for(int j=m; j>=it.s; --j)
            dp[x][j]=(dp[x][j]+dp[it.f][j-it.s])%mod;
    }
}

int32_t main(){
sp;
    cin>>n>>m;
    for(int i=1; i<n; ++i){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].pb({y,w});
        g[y].pb({x,w});
    }
    dfs();
    cout<<ans<<"\n";
    return 0;
}
