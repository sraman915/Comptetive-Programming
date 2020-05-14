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
#define mxn 1005

vector<pair<int,int> > g[mxn];
int n;
int source, destination;
int p[mxn], d[mxn], vis[mxn];


void clean(){
    for(int i = 1; i <= n; ++i){
        g[i].clear();
    }
}

int doit(){
    for(int i = 1; i <= n; ++i){
        d[i] = INT_MAX;
        p[i] = 0;
        vis[i] = 0;
    }
    p[source] = 1;
    d[source] = 0;
    vis[source] = 1;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push({0, source});
    while(!q.empty()){
        int x = q.top().second;
        q.pop();
        for(auto &it: g[x]){
            int w = it.first;
            if(d[it.second] > d[x] + w){
                d[it.second] = d[x] + w;
                p[it.second] = p[x];
                q.push({d[it.second], it.second});
            }
            else if (d[it.second] == d[x] + w)
                p[it.second] += p[x];
        }
    }
    return p[destination];
}


int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        int m, x, y, w;
        cin>>n>>m;
        clean();
        while(m--){
            cin>>x>>y>>w;
            g[x].push_back({w, y});
        }
        cin>>source>>destination;
        cout<<doit()<<"\n";
    }
    return 0;
}
