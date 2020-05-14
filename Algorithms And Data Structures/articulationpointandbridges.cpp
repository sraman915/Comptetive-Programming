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
#define mxn 200005

vector<pair<int,int > > g[mxn], edges;
int vis[mxn], low[mxn], disc[mxn], ap[mxn], par[mxn], bridges[mxn];
int t = 0;
int n, m;

void clean(){
    t = 0;
    edges.clear();
    for(int i = 0; i <= n; ++i){
        low[i] = inf;
        disc[i] = 0;
        vis[i] = 0;
        g[i].clear();
        par[i] = 0;
        ap[i] = 0;
    }
    for(int i = 0; i <= m; ++i)
        bridges[i] = 0;
}

void dfs(int x){
    vis[x] = 1;
    int child = 0;
    low[x] = disc[x] = ++t;
    for(auto &it: g[x]){
        if(vis[it.first] == 0){
            ++child;
            par[it.first] = x;
            dfs(it.first);
            low[x] = min(low[x], low[it.first]);
            if(par[x] == 0 && child > 1)
                ap[x] = 1;
            if(par[x] && disc[x] <= low[it.first])
                ap[x] = 1;
            if(disc[x] < low[it.first])
                bridges[it.second] = 1;
        }
        else{
            if(par[x] != it.first)
                low[x] = min(low[x], disc[it.first]);
        }
    }
}

int32_t main(){
sp;
    cin>>n>>m;
    clean();
    for(int i = 0; i < m; ++i){
        int x, y;
        cin>>x>>y;
        edges.push_back({x, y});
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    int q;
    cin>>q;
    while(q--){
        int c;
        cin>>c;
        if(bridges[c - 1] == 0)
            cout<<"Happy\n";
        else
            cout<<"Unhappy\n";
    }
    return 0;
}