#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
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

vector<int> g[mxn], level[mxn];
int ans[mxn], lev1[mxn], ans1[mxn];
int start[mxn], finish[mxn], t = 0, n, lev[mxn];
vector<pair<int,int> > querybuffer;


void dfs(int x = 1, int p = 0, int levv = 0){
    start[x] = ++t;
    lev[x] = levv;
    level[levv].push_back(start[x]);
    for(auto &it:g[x])
        if(it != p)
            dfs(it, x, levv + 1);
    finish[x] = t;
}

int cntiny(int y, int l){
    int z = 1LL * (upper_bound(level[l].begin(), level[l].end(), finish[y]) - lower_bound(level[l].begin(), level[l].end(), start[y]));
    return z;
}

void dfs1(int x = 1, int p = 0){
    ans[x] = ans1[x];
    for(auto &it:g[x])
        if(it != p){
            dfs1(it, x);
            ans[x] += ans[it];
        }
}


void blowbuffer(){
    while(!querybuffer.empty()){
        pair<int,int> p = querybuffer.back();
        querybuffer.pop_back();
        lev1[p.first] += 1LL*p.second;
    }
    for(int i = 1; i <= n; ++i)
        ans1[i] += lev1[lev[i]];
    dfs1();
    for(int i = 0; i <= n; ++i)
        lev1[i] = 0;
}

int32_t main(){
sp;
    int m, x, y, c;
    cin>>n>>m;
    for(int i = 1; i < n; ++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs();
    int ht = sqrt(m);
    int z;
    while(m--){
        cin>>c;
        if(querybuffer.size() > ht)
            blowbuffer();
        if(c == 1){
            cin>>x>>z;
            if(z)
                querybuffer.push_back({x, z});
        }
        else{
            cin>>x;
            int sum = 1LL * ans[x];
            for(auto &it:querybuffer)
                sum += 1LL * it.second * 1LL * cntiny(x, it.first);
            cout<<sum<<"\n";
        }
    }
    return 0;
}
