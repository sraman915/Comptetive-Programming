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

int id[mxn], sz[mxn];
int a[mxn];

void init(int n){
    for(int i = 0; i <= n; ++i)
        id[i] = i, sz[i] = 1;
}

int root(int i){
    while(i != id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void unn(int p, int q){
    p = root(p);
    q = root(q);
    if(p == q)
        return;
    if(sz[p] < sz[q])
        swap(p, q);
    sz[p] += sz[q];
    sz[q] = 0;
    id[q] = p;
}

int kruskal(vector<pair<int, pair<int,int> > >edges, int n){
    init(n);
    int mincost = 0;
    sort(edges.begin(), edges.end());
    for(auto &it: edges){
        int w = it.first;
        int x = it.second.first;
        int y = it.second.second;
        int x1 = root(x);
        int y1 = root(y);
        if(x1 != y){
            mincost += w;
            unn(x1, y1);
        }
    }
    return mincost;
}

int32_t main(){
sp;
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <=  n; ++i)
        cin>>a[i];
    vector<pair<int,pair<int, int> > > edges;
    while(m--){
        int x, y, w;
        cin>>x>>y>>w;
        edges.push_back({w, {x, y}});
    }
    cout<<kruskal(edges, n);
    return 0;
}
