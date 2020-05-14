/*
SOLUTION BY RAMAN SHARMA
https://www.spoj.com/problems/EC_P/
EC_P - Critical Edges

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
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
#define mxn 705
vector<pi> g[mxn];
vector<int> disc(mxn),low(mxn,inf),vis(mxn),par(mxn),ap(mxn),vis1(mxn*mxn);
int t=0;
void dfs(int x){
vis[x]=1;
low[x]=disc[x]=++t;
int child=0;
for(auto &it:g[x])
    if(!vis[it.f]){
        ++child;
        par[it.f]=x;
        dfs(it.f);
        low[x]=min(low[x],low[it.f]);
        if(par[x]==0&&child>1)ap[x]=1;
        if(par[x]&&disc[x]<=low[it.f])ap[x]=1;
        if(disc[x]<low[it.f])vis1[it.s]=1;
    }
    else{
        if(par[x]!=it.f)
            low[x]=min(low[x],disc[it.f]);
    }

}

int main(){
sp;
int q;
cin>>q;
for(int tt=1; tt<=q; ++tt){
        cout<<"Caso #"<<tt<<"\n";
    int n,m;
    t=0;
    cin>>n>>m;
    for(int i=1; i<=n; ++i){
        g[i].clear();
        vis[i]=0;
        disc[i]=0;
        par[i]=0;
        low[i]=inf;
    }
    for(int i=0; i<=m; ++i)
        vis1[i]=0;
    int x,y;
    vector<pi> ed,bridges;
    for(int i=0; i<m; ++i){
        cin>>x>>y;
        g[x].pb({y,i});
        g[y].pb({x,i});
        if(x>y)swap(x,y);
        ed.pb({x,y});
    }
    for(int i=1; i<=n; ++i)
        if(!vis[i])dfs(i);
    for(int i=0; i<m; ++i)
        if(vis1[i])bridges.pb(ed[i]);
    if(bridges.empty())cout<<"Sin bloqueos\n";
else{
        sort(bridges.begin(),bridges.end());
    cout<<bridges.size()<<"\n";
    for(auto &it:bridges)cout<<it.f<<" "<<it.s<<"\n";
}
}
return 0;}
