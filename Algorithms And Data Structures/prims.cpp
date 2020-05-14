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

vector<pi> g[mxn];
int vis[mxn];

int prim(){
    priority_queue<pi,vector<pi>, greater<pi> > q;
    int x,y;
    int w;
    pi p;
    q.push({0,1});
    int mincost=0;
    while(!q.empty()){
        x=q.top().second;
        w=q.top().first;
        q.pop();
        if(vis[x])
            continue;
        mincost+=w;
        vis[x]=1;
        for(int i=0; i<g[x].size(); ++i){
            y=g[x][i].second;
            if(!vis[y])
                q.push(g[x][i]);
        }
    }
    return mincost;
}

int32_t main() {
sp;
    int n,m;
    cin>>n>>m;
    int w;
    int x,y;
    for(int i=0; i<m; ++i){
        cin>>x>>y>>w;
        g[x].pb({w,y});
        g[y].pb({w,x});
    }
    cout<<prim();
    return 0;
}
