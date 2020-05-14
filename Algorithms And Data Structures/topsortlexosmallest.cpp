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

vector<int> g[mxn],vis(mxn,0),topsort;

void dfs(int s){
    vis[s]=1;
    for(int i=0;i<g[s].size(); ++i){
        int y=g[s][i];
        if(!vis[y])
            dfs(y);
        }
    topsort.push_back(s);
}

int32_t main(){
sp;
    int n,m,u,v;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1; i<=n; ++i)
        sort(g[i].rbegin(), g[i].rend());
    for(int i=n; i>0; --i)
        if(!vis[i])
            dfs(i);

    for(int i=n-1; i>=0; --i)
        cout<<topsort[i]<<" ";
return 0;}
