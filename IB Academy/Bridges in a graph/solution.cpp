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
vector<int> g[N],disc(N),low(N),par(mxn),vis(mxn),ap(mxn);
map<pair<int,int>,int> mp;
int t=0;


void clean(int n){
    for(int i=0; i<=n; ++i){
        g[i].clear();
        vis[i]=0;
        low[i]=1000000000;
        par[i]=0;
        ap[i]=0;
    }
    mp.clear();
    t=0;
}

void make_graph(vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void dfs(int x){
    vis[x]=1;
    low[x]=disc[x]=++t;
    int child=0;
    for(int j:g[x]){
        if(!vis[j]){
            ++child;
            par[j]=x;
            dfs(j);
            low[x]=min(low[x],low[j]);
            if(par[x]==0&&child>1)
                ap[x]=1;
            if(par[x]&&disc[x]<=low[j])
                ap[x]=1;
        if(disc[x]<low[j])
            mp[{min(x,j),max(j,x)}]=1;
    }
    else{
        if(par[x]!=j)
            low[x]=min(low[x],disc[j]);
    }
}
}

vector<vector<int> > bridges(int n,vector<vector<int> > &edges){
    clean(n);
    make_graph(edges);
    for(int i=1; i<=n; ++i)
        if(!vis[i])
            dfs(i);
    vector<vector<int> > bridges;
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        if(x>y)swap(x,y);
        if(mp.find({x,y})!=mp.end()){
            vector<int> v;
            v.push_back(x);
            v.push_back(y);
            bridges.push_back(v);
        }
    }
    sort(bridges.begin(),bridges.end());
    return bridges;
}


int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m,tempm;
cin>>n;
assert(n>=1&&n<=50000);
cin>>m>>tempm;
assert(m>=1&&m<=50000);
map<pair<int,int> ,int> mp;
assert(tempm==2);
int tot=n*(n-1)/2;
assert(m>=1&&m<=tot);
vector<vector<int> > A;
for(int i=0; i<m; ++i){
vector<int> v(2);
cin>>v[0]>>v[1];
if(v[0]>v[1])swap(v[0],v[1]);
assert(v[0]>0&&v[0]<=n);
assert(v[1]>0&&v[1]<=n);
assert(v[0]!=v[1]);
assert(mp.find({v[0],v[1]})==mp.end());
mp[{v[0],v[1]}];
A.pb(v);
}
vector<vector<int > > ans=bridges(n,A);
for(auto &it:ans){
cout<<"[";
for(auto &it1:it)
cout<<it1<<" ";
cout<<"] ";
}
cout<<"\n";
}
return 0;}
