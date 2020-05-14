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


const int N =100005;


vector<pair<int,int> > g[N];
vector<int> vis(N);
int visi[N];
int c=0;

void clean(int n){
    for(int i=0; i<=n; ++i){
            g[i].clear();
            vis[i]=0;
            visi[i]=0;
    }
}

void make_graph(vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        int w=it[2];
        g[x].push_back({w,y});
        g[y].push_back({w,x});
    }
}

void dfs(int x){
    if(!visi[x])
        ++c;
    visi[x]=1;
    for(auto &it:g[x]){
        if(visi[it.second]==0)
            dfs(it.second);
    }
}



int MinimumCostToConnectCities(int n,vector<vector<int> > &edges){
    clean(n);
    make_graph(edges);
    c=0;
    dfs(1);
    assert(c==n);
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push({0,1});
    int mincost=0;
    while(!q.empty()){
        int x=q.top().second;
        int w=q.top().first;
        q.pop();
        if(vis[x]) continue;
        mincost+=w;
        vis[x]=1;
        for(int i=0; i<g[x].size(); ++i){
            int y=g[x][i].second;
            if(!vis[y])
                q.push(g[x][i]);
        }
    }
    return mincost;
}



int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=100000);
    int m,tempm;
    cin>>m>>tempm;
    int tot=(n*(n-1))/2;
    assert(m>=n-1&&m<=tot);
    assert(tempm==3);
    map<pi,int> mp;
    vector<vector<int> > v(m,vector<int> (3));
    for(int i=0; i<m; ++i){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
        assert(v[i][2]>=1&&v[i][2]<=10000);
        assert(v[i][0]!=v[i][1]);
        assert(v[i][1]>=1&&v[i][1]<=n);
        assert(v[i][0]>=1&&v[i][0]<=n);
        if(v[i][0]<v[i][1])
            swap(v[i][0],v[i][1]);
        assert(mp.find({v[i][0],v[i][1]})==mp.end());
        mp[{v[i][0],v[i][1]}];
    }
    int ans=MinimumCostToConnectCities(n,v);
    cout<<ans<<"\n";
}
return 0;}

