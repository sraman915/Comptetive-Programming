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

vector<int> tree[mxn];
vector<pair<int,int> >  g[mxn], edges;
int disc[mxn], low[mxn], par[mxn], vis[mxn], ap[mxn], bridges[mxn];
int t = 0, cmpno, visited[mxn];
int a[mxn];
int n, m;

queue<int> Q[mxn];

void clean(){
    t = 0;
    cmpno = 0;
    edges.clear();
    for(int i = 0; i <= n; ++i){
        low[i] = inf;
        disc[i] = 0;
        vis[i] = 0;
        par[i] = 0;
        ap[i] = 0;
        visited[i] = 0;
        g[i].clear();
        tree[i].clear();
        while(!Q[i].empty())
            Q[i].pop();
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

void dfs1(int v) {
    int currcmp = cmpno;
    Q[currcmp].push(v);
    visited[v] = 1;
    while(!Q[currcmp].empty())  {
        int u = Q[currcmp].front();
        Q[currcmp].pop();
        for(auto &it: g[u]){
            if(visited[it.first])
                continue;
            if(bridges[it.second]){
                cmpno++;
                tree[currcmp].push_back(cmpno);
                tree[cmpno].push_back(currcmp);
                dfs1(it.first);
            }
            else{
                Q[currcmp].push(it.first);
                visited[it.first] = 1;
            }
        }
    }
}

int diameteroftree = 0;

int dfs2(int x, int p = 0){
    int m1 = 0, m2 = 0;
    for(auto &it: tree[x])
        if(it != p){
            int m = dfs2(it, x);
            if(m > m1){
                m2 = m1;
                m1 = m;
            }
            else if(m > m2)
                m2 = m;
        }
    diameteroftree = max(diameteroftree , m1 + m2);
    return m1 + 1;
}

int32_t main(){
sp;
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        int x, y;
        cin>>n>>m;
        clean();
        for(int i = 0; i < m;++i){
            cin>>x>>y;
            edges.push_back({x, y});
            g[x].push_back({y, i});
            g[y].push_back({x, i});
        }
        for(int i = 1; i <= n; ++i)
            if(vis[i] == 0)
                dfs(i);
        for(int i = 1; i <= n; ++i)
            if(visited[i] == 0){
                ++cmpno;
                dfs1(i);
            }
        diameteroftree = 0;
        dfs2(1, 0);
        cout<<cmpno - 1<<" "<<diameteroftree<<"\n";
    }
    return 0;
}
