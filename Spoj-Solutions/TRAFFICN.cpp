/*
TRAFFICN - Traffic Network
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mxn 10001
#define mp make_pair
#define pb push_back
#define inf 10000000000
#define ll long long
#define pi pair<ll,int>
vector<pi> g[mxn],r[mxn];
vector<ll> d1(mxn),d2(mxn);
void dijkstra1(int sc){
d1[sc]=0LL;
int x,y;
ll w;
priority_queue<pi,vector<pi>,greater<pi> > q;
q.push(mp(0LL,sc));
while(!q.empty()){
    x=q.top().second;
    q.pop();
    for(int i=0; i<g[x].size(); ++i){
        y=g[x][i].second;
        w=g[x][i].first;
        if(d1[y]>d1[x]+w){
            d1[y]=d1[x]+w;
            q.push(mp(d1[y],y));
        }
    }
}
}
void dijkstra2(int dt){
d2[dt]=0LL;
int x,y;
ll w;
priority_queue<pi,vector<pi>,greater<pi> > q;
q.push(mp(0LL,dt));
while(!q.empty()){
    x=q.top().second;
    q.pop();
    for(int i=0; i<r[x].size(); ++i){
        y=r[x][i].second;
        w=r[x][i].first;
        if(d2[y]>d2[x]+w){
            d2[y]=d2[x]+w;
            q.push(mp(d2[y],y));
        }
    }
}
}

int main(){
    sp;
int t;
cin>>t;
while(t--){
    for(int i=0; i<mxn;++i){
        g[i].clear();
        r[i].clear();
        d1[i]=inf;
        d2[i]=inf;
            }
    int n,sc,dt,m,k,x,y;
    ll w,ans=inf;
    cin>>n>>m>>k>>sc>>dt;
     while(m--){
        cin>>x>>y>>w;
        g[x].pb(mp(w,y));
        r[y].pb(mp(w,x));
     }
     dijkstra1(sc);
     dijkstra2(dt);
    // cout<<d1[t]<<" "<<d2[t]<<"\n";
    ans=min(d1[dt],d2[sc]);
    while(k--){
        cin>>x>>y>>w;
        ans=min(ans,min(d1[x]+d2[y]+w,d2[x]+d1[y]+w));
    }
    if(ans==inf) cout<<"-1\n";
    else cout<<ans<<"\n";
}
return 0;}
