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

vector<int> g[mxn];
int color[mxn];
map<int,int> in[mxn];
int mx[mxn], id[mxn], sz[mxn];
int sum[mxn], out[mxn];
int n;

void init(){
    for(int i = 0; i <= n;++i)
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
    id[q] = p;
    sz[p] += sz[q];
    sz[q] = 0;
    for(auto &it: in[q]){
        int c = it.first;
        int cnt = it.second;
        in[p][c] += cnt;
        if(in[p][c] > mx[p]){
            mx[p] = in[p][c];
            sum[p] = c;
        }
        else if(in[p][c] == mx[p])
            sum[p] += c;
    }
    in[q].clear();
}

void dfs(int x, int p){
    for(auto &it: g[x])
        if(it != p){
            dfs(it, x);
        unn(it, x);
    }
    out[x] = sum[id[x]];
}

int32_t main(){
sp;
    cin>>n;
    init();
    int x, y;
    for(int i = 1; i <= n; ++i){
        cin>>color[i];
        in[i][color[i]] = 1;
        mx[i] = 1;
        sum[i] = color[i];
    }
    for(int i = 1; i < n; ++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i)
        cout<<out[i]<<" ";
    return 0;
}
