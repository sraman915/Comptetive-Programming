/*
CAPCITY - Capital City
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mxn 100001
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
vector<int> g[mxn],r[mxn],vis(mxn),tp,id(mxn),incom(mxn);
int cc=0;

void dfs(int s){
vis[s]=true;
for(int i:g[s])
    if(!vis[i])
    dfs(i);
tp.pb(s);
}

void dfs1(int s){
vis[s]=false;
id[s]=cc;
for(int i:r[s])
    if(vis[i])
    dfs1(i);
}

int main(){
int n,m,x,y;
cin>>n>>m;
while(m--){
    cin>>x>>y;
    g[y].pb(x);
    r[x].pb(y);
}
for(int i=1; i<=n; ++i)
    if(!vis[i]) dfs(i);

int l=tp.size();
for(int i=l-1; i>=0; --i){
        x=tp[i];
    if(vis[x]){
        dfs1(x);
        ++cc;}
}
for(int i=1; i<=n; ++i){
    for(int j:g[i]){
        if(id[i]!=id[j])
            incom[id[j]]++;
    }
}
y=0;
for(int i=0; i<cc; ++i){
    if(incom[i]==0) ++y;
}
if(y>1){
    cout<<"-1\n";
    return 0;
}
y=0;
for(int i=1; i<=n; ++i){
    if(incom[id[i]]==0) ++y;
}
cout<<y<<"\n";
for(int i=1; i<=n; ++i)
    if(incom[id[i]]==0) cout<<i<<" ";
return 0;}
