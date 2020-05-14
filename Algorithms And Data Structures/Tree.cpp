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

int n;
vector<int> g[mxn], par(mxn), level(mxn);
int dp[18][mxn];
int a[mxn];

void dfs(int x, int parent){
    par[x] = parent;
    dp[0][x] = parent;
    for(auto &it: g[x])
        if(it != parent){
            level[it] = 1 + level[x];
            dfs(it, x);
    }
}

int getp(int x, int k){
    for(int i = 0; i < 18; ++i){
        if(k & (1 << i))
            x = dp[i][x];
    }
    return x;
}

int lca(int x, int y){
    if(level[x] > level[y])
        swap(x, y);
    y = getp(y, level[y] - level[x]);
    if(x == y)
        return x;
    for(int i = 17; i >= 0; i--){
        if(dp[i][x] != dp[i][y]){
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return par[x];
}

void pre(){
    dfs(1, 0);
    for(int i = 1; i <= n; ++i)
        dp[0][i] = par[i];
    for(int i = 1; i < 18; ++i)
        for(int j = 1; j <= n; ++j)
            if(dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
}


void clean(){
    for(int i = 0; i <= n; ++i){
        g[i].clear();
        a[i] = 0;
        level[i] = 0;
        par[i] = 0;
        for(int j = 0; j < 18; ++j)
            dp[j][i] = -1;
    }
}

int ans(int x, int y){
    if(x == y)
        return a[x];
    int z = lca(x, y);
    return a[z];
}

int32_t main(){
sp;
    int t;
    cin >> t;
    while(t--){
        int q, x, y, z;
        cin >> n >> q;
        clean();
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        for(int i = 1; i < n; ++i){
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        pre();
        while(q--){
            cin >> x >> y;
            cout << ans(x, y)<<"\n";
        }
    }
    return 0;
}
