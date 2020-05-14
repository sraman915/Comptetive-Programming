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

vector<int> g[mxn], r[mxn], scc[mxn], topsort, a(mxn), val(mxn), color(mxn);
vector<pi> edges;
int vis[mxn], c = 0;

void dfs0(int x){
    vis[x] = 1;
    for(auto &it: g[x])
        if(vis[it] == 0)
            dfs0(it);
    topsort.push_back(x);
}

void dfs1(int x){
    vis[x] = 1;
    color[x] = c;
    for(auto &it: r[x])
        if(vis[it] == 0)
            dfs1(it);
}

void dfs2(int x){
    vis[x] = 1;
    for(auto &it: scc[x])
        if(!vis[it])
            dfs2(it);
    topsort.push_back(x);
}


int32_t main(){
sp;
    int n, m, x, y;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];

    for(int i = 0; i < m; ++i){
        cin>>x>>y;
        edges.push_back({x, y});
        g[x].push_back(y);
        r[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs0(i);
    for(int i = 0; i < n; ++i)
        vis[i] = 0;

    while(!topsort.empty()){
        x = topsort.back();
        topsort.pop_back();
        if(!vis[x]){
            ++c;
            dfs1(x);
        }
    }

    for(int i  = 0; i < n; ++i)
        vis[i] = 0;

    for(int i = 0; i < m; ++i){
        x = edges[i].first;
        y = edges[i].second;
        if(color[x] != color[y])
            scc[color[x]].push_back(color[y]);
    }
    for(int i = 1; i <= c; ++i)
        if(!vis[i])
            dfs2(i);
    return 0;
}
