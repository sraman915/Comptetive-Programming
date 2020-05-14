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
//#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
//#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 500005


const int N =100005;
vector<int> g[N],r[N],scc[N],topsort,vis(N);
int c=0;

void clean(int n){
    for(int i=0; i<=n; ++i){
        g[i].clear();
        r[i].clear();
        scc[i].clear();
        vis[i]=0;
    }
    c=0;
    topsort.clear();
}

void make_graph(vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        g[x].push_back(y);
        r[y].push_back(x);
    }
}

void dfs0(int x){
    vis[x]=1;
    for(auto &it:g[x])
        if(!vis[it])
            dfs0(it);
    topsort.push_back(x);
}


void dfs1(int x){
    vis[x]=1;
    scc[c].push_back(x);
    for(auto &it:r[x])
        if(!vis[it])
            dfs1(it);
}

vector<vector<int> > StronglyConnectedComponents(int n,vector<vector<int> > &edges){
    clean(n);
    make_graph(edges);
    vector<vector<int> > stronglyConnectedComponents;

    for(int i=1; i<=n; ++i)
        if(!vis[i])
            dfs0(i);

    for(int i=0; i<=n; ++i)
        vis[i]=0;

    while(!topsort.empty()){
        int x=topsort.back();
        topsort.pop_back();
        if(!vis[x]){
            ++c;
            dfs1(x);
        }
    }

    for(int i=1; i<=c; ++i){
        sort(scc[i].begin(),scc[i].end());
        assert(scc[i].size()>0);
        stronglyConnectedComponents.push_back(scc[i]);
    }
    sort(stronglyConnectedComponents.begin(),stronglyConnectedComponents.end());
    return stronglyConnectedComponents;
}


int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m,tempm;
cin>>n;
assert(n>=1&&n<=100000);
cin>>m>>tempm;
assert(m>=1&&m<=100000);
map<pair<int,int> ,int> mp;
assert(tempm==2);
vector<vector<int> > A;
for(int i=0; i<m; ++i){
vector<int> v(2);
cin>>v[0]>>v[1];
assert(v[0]>0&&v[0]<=n);
assert(v[1]>0&&v[1]<=n);
assert(v[0]!=v[1]);
assert(mp.find({v[0],v[1]})==mp.end());
mp[{v[0],v[1]}];
A.pb(v);
}
vector<vector<int > > ans=StronglyConnectedComponents(n,A);
for(auto &it:ans){
cout<<"[";
for(auto &it1:it)
cout<<it1<<" ";
cout<<"] ";
}
cout<<"\n";
}
return 0;}
