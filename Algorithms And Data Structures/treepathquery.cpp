#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

int start[mxn],finish[mxn],t = 0, att[mxn], a[mxn], par[mxn], level[mxn], dp[18][mxn], magic = 741;
int b[mxn],c[mxn],ans[mxn];
vector<int> g[mxn];
map<int,int> mp;
int n;

void dfs(int x = 1, int p = 0){
    start[x] = ++t;
    att[t] = x;
    par[x] = p;
    dp[0][x] = p;
    for(auto &it: g[x])
        if(it != p){
            level[it] = 1 + level[x];
            dfs(it,x);
        }
    finish[x] = ++t;
    att[t] = x;
}

int getp(int x, int k){
    for(int i = 0; i < 18; ++i)
        if(k & (1<<i)) x = dp[i][x];
    return x;
}

int lca(int x, int y){
    if(x == y)
        return x;
    if(level[x] > level[y])
        swap(x,y);
    y = getp(y, level[y] - level[x]);
    if(x == y)
        return x;
    for(int i = 17; i > -1; --i)
        if(dp[i][x] != dp[i][y]){
            x = dp[i][x];
            y = dp[i][y];
        }
    return par[x];
}

void pre(){
    memset(dp, -1, sizeof dp);
    dfs();
    for(int i = 1; i < 18; ++i)
        for(int j = 1; j <= n; ++j)
            if(dp[i - 1][j] != -1)
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
}


struct query{
    int x, y, l, r, id, xy;
    query(){
        x = 0, y = 0, l = 0, r = 0, id = 0, xy = 0;
    }
    query(int x, int y, int l, int r, int id, int xy){
        this->x = x;
        this->y = y;
        this->l = l;
        this->r = r;
        this->id = id;
        this->xy = xy;
    }
};

bool compare(const query &a,const query &b){
    int x = a.l / magic;
    int y = b.l / magic;
    if(x != y)
        return x < y;
    if(x & 1)
        return a.r > b.r;
    return a.r < b.r;
}

int main(){
//sp;
    int t;
    cin>>t;
    while(t--){
        int x, y, qq;
        cin>>n>>qq;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
            mp[a[i]];
        }
        x=0;
        for(auto &it:mp)
            it.second = ++x;
        for(int i = 1; i <= n; ++i)
            a[i] = mp[a[i]];
        for(int i = 1; i < n; ++i){
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        pre();
        query q[qq + 1];
        for(int i = 1; i <= qq; ++i){
            cin>>x>>y;
            q[i].id = i;
            if(level[x] > level[y])
                swap(x, y);
            q[i].xy = lca(x, y);
            q[i].x = x;
            q[i].y = y;
            if(q[i].xy == x){
                q[i].l = start[x];
                q[i].r = start[y];
            }
            else{
                q[i].l = finish[x];
                q[i].r = start[y];
            }
        }

        y = 0;
        sort(q + 1, q + 1 + qq, compare);
        int curl = q[1].l, curr = q[1].l - 1;
        int l, r, z, id;
        for(int i = 1; i <= qq; ++i){
            l = q[i].l;
            r = q[i].r;
            id = q[i].id;
            while(curr < r){
                ++curr;
                x = att[curr];
                b[x] ^= 1;
                if(b[x]){
                    ++c[a[x]];
                    if(c[a[x]] == 1)
                        ++y;
                }
                else {
                    --c[a[x]];
                    if(c[a[x]] == 0)
                        --y;
                }
            }
            while(curl > l){
                --curl;
                x = att[curl];
                b[x] ^= 1;
                if(b[x]){
                    ++c[a[x]];
                    if(c[a[x]] == 1)
                        ++y;
                }
                else {
                    --c[a[x]];
                    if(c[a[x]] == 0)
                        --y;
                }
            }
            while(curr > r){
                x = att[curr];
                b[x] ^= 1;
                if(b[x]){
                    ++c[a[x]];
                    if(c[a[x]] == 1)
                        ++y;
                }
                else {
                    --c[a[x]];
                    if(c[a[x]] == 0)
                        --y;
                }
                --curr;
            }
            while(curl < l){
                x = att[curl];
                b[x] ^= 1;
                if(b[x]){
                    ++c[a[x]];
                    if(c[a[x]] == 1)
                        ++y;
                }
                else {
                    --c[a[x]];
                    if(c[a[x]] == 0)
                        --y;
                }
                ++curl;
            }
            if(q[i].x != q[i].xy && q[i].y != q[i].xy){
                x = q[i].xy;
                b[x] ^= 1;
                if(b[x]){
                    ++c[a[x]];
                    if(c[a[x]] == 1)
                        ++y;
                }
                else {
                    --c[a[x]];
                    if(c[a[x]] == 0)
                        --y;
                }
            }
            ans[id]=y;
            if(q[i].x != q[i].xy && q[i].y != q[i].xy){
                x = q[i].xy;
                b[x] ^= 1;
                if(b[x]){
                    ++c[a[x]];
                    if(c[a[x]] == 1)
                        ++y;
                }
                else{
                    --c[a[x]];
                    if(c[a[x]] == 0)
                        --y;
                }
            }
        }
        for(int i = 1; i <= qq; ++i)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
