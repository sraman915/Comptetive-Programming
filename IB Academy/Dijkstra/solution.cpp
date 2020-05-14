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


#define pi pair<int,int>
const int N =100005;
vector<pi> g[N];
int vis[N];

const int inf=1000000000;

void clean(int n){
    for(int i=0; i<=n; ++i){
        g[i].clear();
        vis[i]=0;
    }
}

void make_graph(vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        int w=it[2];
        g[x].push_back(make_pair(w,y));
        g[y].push_back(make_pair(w,x));
    }
}

vector<int> dijkstra(int n,vector<vector<int> > &edges,int source){
    clean(n);
    make_graph(edges);
    vector<int> distance(n,inf);
    priority_queue<pi,vector<pi>, greater<pi> > q;
    distance[source]=0;
    q.push(make_pair(0,source));
    while(!q.empty()){
        pi p=q.top();
        int x=p.second;
        q.pop();
        if(vis[x])
            continue;
        vis[x]=1;
        for(int i=0; i<g[x].size(); ++i){
            int y=g[x][i].second;
            int w=g[x][i].first;
            if(distance[x]+w<distance[y]){
                distance[y]=distance[x]+w;
                q.push(make_pair(distance[y],y));
            }
        }
    }
    for(int i=0; i<n; ++i){
        if(distance[i]==inf)
            distance[i]=-1;
    }
    return distance;
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m,tempm;
cin>>n;
cin>>m>>tempm;
map<pi,int> mp;
assert(tempm==3);
int tot=n*(n-1)/2;
assert(m>=1&&m<=tot);
vector<vector<int> > A;
for(int i=0; i<m; ++i){
vector<int> v(3);
cin>>v[0]>>v[1]>>v[2];
if(v[0]>v[1])swap(v[0],v[1]);
assert(v[0]>=0&&v[0]<n);
assert(v[1]>=0&&v[1]<n);
assert(v[0]!=v[1]);
assert(v[2]>=1&&v[2]<=1000);
assert(mp.find({v[0],v[1]})==mp.end());
mp[{v[0],v[1]}];
A.pb(v);
}
int source;
cin>>source;
assert(source>=0&&source<n);
vector<int> ans=dijkstra(n,A,source);
for(auto &it:ans)cout<<it<<" ";
cout<<"\n";
}
return 0;}
