#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mxn 200005

vector<int> g[mxn],sz(mxn,0);
vector<int> centroid;

int n;
void dfs(int a,int p){
bool ch=true;
int sum=0;
for(int i=0;i<g[a].size();i++){
    int y=g[a][i];
    if(y==p) continue;
    dfs(y,a);
    sz[a]+=sz[y];
    if(sz[y]>n/2) ch=false;
}
sz[a]++;
if(n-sz[a]>n/2) ch=false;
if(ch) centroid.pb(a);
}
int main(){
cin>>n;
for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
}
dfs(1,0);
for(int i:centroid)cout<<i<<" ";

return 0;}
