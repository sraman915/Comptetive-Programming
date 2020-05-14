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
#define mxn 30005

vector<int> g[mxn];
int vis[mxn];

void dfs(int x){
    vis[x]=1;
    for(int &i:g[x])
        if(!vis[i])dfs(i);
}

int start;
vector<int> q;

bool dfs1(int x,int p){
    vis[x]=1;
    for(int i:g[x]){
        if(i!=p){
            if(vis[i]){
                start=i;
            return true;
            }
            q.pb(i);
            if(dfs1(i,x))
                return true;
            q.pop_back();
    }
    }
    return false;
}

int32_t main(){
sp;
    int n,m,x,y;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    memset(vis,0,sizeof vis);
    q.pb(1);
    dfs1(1,0);
    int l=q.size();
    int i=0;
    while(i<l&&q[i]!=start)
        ++i;
    vector<int> v;
    queue<int> qq;
    int dis[n+1];
    memset(dis,0,sizeof dis);
    for(int i=0; i<=n; ++i)
        dis[i]=inf;
    while(i<l){
        qq.push(q[i]);
        dis[q[i]]=0;
        ++i;
    }
    while(!qq.empty()){
        x=qq.front();
        qq.pop();
        for(auto &it:g[x])
            if(dis[it]>dis[x]+1){
                dis[it]=1+dis[x];
            qq.push(it);
        }
    }
    for(int i=1; i<=n; ++i)
        cout<<dis[i]<<" ";
return 0;}
