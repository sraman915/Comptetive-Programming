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

map<pi,int> mp;
int n;
vector<int> g[mxn];
int dp1[mxn],dp[19][mxn],level[mxn],par[mxn],ans[mxn];

void dfs(int x,int p){
    par[x]=p;
    dp[0][x]=p;
    for(auto &it:g[x]){
        if(it!=p){
            level[it]=1+level[x];
            dfs(it,x);
        }
    }
}

int getp(int x,int k){
    for(int i=0; i<18; ++i){
        if(k&(1<<i))
            x=dp[i][x];
    }
    return x;
}

int lca(int x,int y){
    if(x==y)
        return x;
    if(level[x]>level[y])
        swap(x,y);
    y=getp(y,level[y]-level[x]);
    if(x==y)
        return x;
    for(int i=17;i>=0;i--){
        if(dp[i][x]!=dp[i][y]){
            x=dp[i][x];
            y=dp[i][y];
        }
    }
    return par[x];
}

void pre(){
    memset(dp,-1,sizeof dp);
    dfs(1,0);
    for(int i=1; i<=n; ++i)
        dp[0][i]=par[i];
    for(int i=1; i<18; ++i)
        for(int j=1; j<=n; ++j)
            if(dp[i-1][j]!=-1)
                dp[i][j]=dp[i-1][dp[i-1][j]];
}

void dfs1(int x,int p){
    for(auto &it:g[x])
        if(it!=p){
            dfs1(it,x);
            dp1[x]+=dp1[it];
    }
}

int32_t main(){
sp;
    cin>>n;
    int x,y,q;
    for(int i=1; i<n; ++i){
        cin>>x>>y;
        mp[{x,y}]=mp[{y,x}]=i;
        g[x].pb(y);
        g[y].pb(x);
    }
    cin>>q;
    pre();
    while(q--){
        cin>>x>>y;
        int z=lca(x,y);
        dp1[x]++;
        dp1[y]++;
        dp1[z]-=2;
    }
    dfs1(1,0);
    for(int i=2; i<=n; ++i)
        ans[mp[{i,par[i]}]]=dp1[i];
    for(int i=1; i<n; ++i)
        cout<<ans[i]<<" ";
return 0;}
