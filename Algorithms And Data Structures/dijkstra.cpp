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

int n,m;
vector<pair<int,int> > g[mxn];
int d[mxn], vis[mxn];

void dijkstra(int s){
    d[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push({0, s});
    while(!q.empty()){
        pair<int,int> p = q.top();
        int x = p.second;
        q.pop();
        if(vis[x])
            continue;
        vis[x] = 1;
        for(int i = 0; i < g[x].size(); ++i){
            int y = g[x][i].second;
            int w = g[x][i].first;
            if(d[x] + w < d[y]){
                d[y] = d[x] + w;
                q.push({d[y], y});
            }
        }
    }
}

int32_t main() {
sp;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0; i <= n; ++i){
            vis[i] = 0;
            g[i].clear();
            d[i] = inf;
        }
        int x, y, w;
        while(m--){
            cin>>x>>y>>w;
            g[x].push_back({w, y});
            g[y].push_back({w, x});
        }
        int s;
        cin>>s;
        dijkstra(s);
        for(int i = 1; i <= n; ++i){
            if(d[i] == inf)
                cout<<"-1 ";
            else
                cout<<d[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
