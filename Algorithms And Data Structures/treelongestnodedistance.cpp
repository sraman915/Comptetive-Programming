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

int dp[mxn],dp1[mxn],ans[mxn];
vector<int> g[mxn],g1[mxn];

int dfs(int x,int p){
    int m1=0,m2=0;
    for(int i=0; i<g[x].size(); ++i)
        if(g[x][i]!=p){
            int m=dfs(g[x][i],x);
            if(m>m1){
                m2=m1;
                m1=m;
            }
            else if(m>m2)
                m2=m;
            g1[x][i]=m;
        }
    dp[x]=m1;
    return m1+1;
}

void dfs2(int x,int p){
    for(int i=0; i<g[p].size(); ++i)
        if(g[p][i]!=x)
            dp1[x]=max(dp1[x],g1[p][i]+1);
    if(p)
        dp1[x]=max(dp1[x],dp1[p]+1);
    for(auto &it:g[x])
        if(it!=p)
            dfs2(it,x);
}

int32_t main(){
sp;
    int n;
    cin>>n;
    for(int i=1; i<n; ++i){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        g1[x].push_back(0);
        g1[y].push_back(0);
    }
    dfs(1,0);
    dfs2(1,0);
    for(int i=1; i<=n; ++i)
        ans[i]=max(dp[i],dp1[i]);
    for(int i=1; i<=n; ++i)
            cout<<ans[i]<<" ";
    return 0;
}
