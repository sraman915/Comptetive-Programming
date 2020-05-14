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
#define mxn 100005

vector<int> g[mxn];
int dp[mxn][20];
int subsize[mxn], depth[mxn];
int chainHead[mxn], chainPos[mxn], chainSize[mxn], chainInd[mxn], chainNo = 0, l, ptr;
int posInBase[mxn], baseArray[mxn];
int a[mxn];
int n;
vector<int> tree1[4*mxn], tree2[4*mxn];

vector<int> mergee(vector<int> a, vector<int> b){
    vector<int> ans;
    int n = a.size();
    int m = b.size();
    int i = 0,j = 0;
    while(i < n && j < m){
        if(a[i] < b[j])
            ans.push_back(a[i++]);
        else
            ans.push_back(b[j++]);
    }
    while(i < n)
        ans.push_back(a[i++]);
    while(j < m)
        ans.push_back(b[j++]);
    return ans;
}

vector<int> presum(vector<int> a){
    for(int i = 1; i < a.size(); ++i)
        a[i] += a[i - 1];
    return a;
}

vector<int> build(int i, int l, int r){
    if(l == r){
        tree1[i].push_back(baseArray[l]);
        tree2[i].push_back(baseArray[l]);
    }
    else{
        int m = (l + r) >> 1;
        tree1[i] = mergee(build(i + i + 1, l, m), build(2 * i + 2, m + 1, r));
        tree2[i] = presum(tree1[i]);
    }
    return tree1[i];
}

int query(int i, int l, int r, int ql, int qr, int k){
    if(ql > qr)
        swap(ql, qr);
    if(ql <= l && r <= qr){
        int x = upper_bound(tree1[i].begin(), tree1[i].end(), k) - tree1[i].begin();
        if(x == 0)
            return x;
        return tree2[i][x - 1];
    }
    if(qr < l || r < ql)
        return 0;
    int m = (l + r) >> 1;
    int f = query(2 * i + 1, l, m, ql, qr, k) + query(2 * i + 2, m + 1, r, ql, qr, k);
    return f;
}

int lca(int u, int v){
    if(depth[u] < depth[v])
        swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i = 0; i < l; ++i)
        if((diff>>i) & 1)
            u = dp[u][i];
    if(u == v)
        return u;
    for(int i = l - 1; i >= 0; --i)
        if(dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    return dp[u][0];
}

int dfs(int node, int p, int d = 0){
    dp[node][0] = p;
    depth[node] = d;
    int sum = 1;
    for(auto &u: g[node])
        if(u != p)
            sum += dfs(u,node,d+1);
    subsize[node] = sum;
    return sum;
}


void hld(int node, int p){
    if(chainHead[chainNo] == -1)
        chainHead[chainNo] = node;
    chainInd[node] = chainNo;
    chainPos[node] = chainSize[chainNo];
    chainSize[chainNo]++;
    posInBase[node] = ptr;
	baseArray[ptr++] = a[node];
    int sc = -1, mx = 0;
    for(auto &it:g[node])
        if(it != p && mx < subsize[it]){
            sc = it;
            mx = subsize[it];
        }
    if(sc != -1)
        hld(sc, node);
    for(auto &it: g[node])
        if(it != p && it != sc){
            chainNo++;
            hld(it, node);
        }
}

int query_hld2(int u, int v, int k){
    int ans = 0;
    while(chainInd[u] != chainInd[v]){
        ans += query(0, 0, ptr - 1, posInBase[u], posInBase[chainHead[chainInd[u]]], k);
        u = dp[chainHead[chainInd[u]]][0];
    }
    ans += query(0, 0, ptr - 1, posInBase[u], posInBase[v], k);
    return ans;
}

int query_hld(int u, int v, int k){
    int x = lca(u, v);
    int ans = query_hld2(u, x, k) + query_hld2(v, x, k);
    ans -= query_hld2(x, x, k);
    return ans;
}

void init(){
    l = ceil(1.0 * log2(n));
    chainNo = 0;
    ptr = 0;
    for(int i = 0; i <= n; ++i){
        g[i].clear();
        depth[i] = 0;
        subsize[i] = 0;
        chainHead[i] = -1;
        chainInd[i] = 0;
        chainSize[i] = 0;
        chainPos[i] = 0;
        posInBase[i] = 0;
        baseArray[i] = 0;
        for(int j = 0; j < l; ++j)
            dp[i][j] = -1;
    }
}

void pre(){
    dfs(0, -1);
    for(int i = 1; i < l; ++i)
        for(int j = 0; j < n; ++j)
            if(dp[j][i - 1] != -1)
                dp[j][i] = dp[dp[j][i - 1]][i - 1];
    hld(0, -1);
    build(0, 0, ptr - 1);
}

int32_t main(){
sp;
    cin>>n;
    init();
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    for(int i = 1; i < n; ++i){
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pre();
    int q;
    cin>>q;
    while(q--){
        int x,y,w;
        cin>>x>>y>>w;
        int ans = query_hld(x - 1, y - 1, w);//sum of nodes having weight atmost w on path from x to y
        cout<<ans<<"\n";
    }
    return 0;
}
