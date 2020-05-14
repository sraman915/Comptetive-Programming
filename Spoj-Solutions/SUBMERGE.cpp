/*
SOLUTION BY RAMAN SHARMA
SUBMERGE - Submerging Islands
https://www.spoj.com/problems/SUBMERGE/
*/

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
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 10005
vector<int> g[mxn],disc(mxn),low(mxn,100000000),par(mxn),vis(mxn),ap(mxn);
map<pi,int> mp;
int t=0;
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
        if(par[x]==0&&child>1)ap[x]=1;
        if(par[x]&&disc[x]<=low[j])ap[x]=1;
       // if(disc[x]<low[j])mp[{min(x,j),max(j,x)}]=1;
    }
    else{
        if(par[x]!=j)
        low[x]=min(low[x],disc[j]);
    }
}
}


int main(){
sp;
    int n,m,x,y,c;
    while(1){
    cin>>n>>m;
    if(n==0&&m==0)break;
    vector<pi> e;
    for(int i=0; i<m; ++i){
        cin>>x>>y;
        e.pb({x,y});
        g[x].pb(y);
        g[y].pb(x);}
        for(int i=1; i<=n; ++i)
            if(!vis[i])dfs(i);
 int z=0;
 for(int i=1; i<=n; ++i)z+=ap[i];
 cout<<z<<"\n";
 for(int i=1; i<=n; ++i){
    g[i].clear();
    low[i]=100000000;
    vis[i]=0;
    par[i]=0;
    disc[i]=0;
    ap[i]=0;
 }
 t=0;
    }
return 0;}
