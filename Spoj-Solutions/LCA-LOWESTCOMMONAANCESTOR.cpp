/*
LCA-LOWEST COMMON ANCESTOR
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>g[1005];
int sparse[1005][16],level[1005],parent[1005],visited[1005];
void dfs(int a,int p){
if(visited[a]==0){
    visited[a]=1;
    int i;
    level[a]=level[p]+1;
    parent[a]=p;
    for(i=0;i<g[a].size();i++){
        dfs(g[a][i],a);
    }
}
}
int getparent(int u,int k){
for(int i=0;i<17;i++){
    if(k&1) u=sparse[u][i];
    k >>= 1;
}
return u;
}
int lca(int u,int v){
if(level[u]>level[v]){
    u=getparent(u,level[u]-level[v]);
}
else if(level[v]>level[u]){
    v=getparent(v,level[v]-level[u]);
}
if(u==v){
    return u;
}
for(int i=15;i>=0;i--){
    if(sparse[u][i]!=sparse[v][i]){
        u=sparse[u][i];
        v=sparse[v][i];
    }

}
 return parent[u];
}
int main(){
    int t;
    cin>>t;
    for(int xy=1; xy<=t; ++xy){
            for(int i=0; i<1005; ++i){
                g[i].clear();
            }
            memset(visited,0,sizeof(visited));
            memset(level,0,sizeof(level));
            memset(parent,0,sizeof(parent));
            memset(sparse,0,sizeof(sparse));
int n,a,b,i,j,m;
cin>>n;
for(i=1;i<=n;i++){
    cin>>m;
    while(m--)
  {cin>>a;
  g[a].push_back(i);
  g[i].push_back(a);
  }
}
for(i=0;i<1001;i++){
    for(j=0;j<16;j++){
        sparse[i][j]=-1;
    }
}
level[0]=-1;
parent[1]=0;
dfs(1,0);
for(i=0;i<=n;i++){
    sparse[i][0]=parent[i];
}
for(j=1;(1<<j)<=n;j++){
    for(i=1;i<=n;i++){
        if(sparse[i][j-1]!=-1){
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];}}
}
int q,u,v;
cin>>q;
cout<<"Case "<<xy<<":"<<endl;
for(i=0;i<q;i++){
    cin>>u>>v;
    int l=lca(u,v);
    cout<<l<<endl;}}
return 0;
}
