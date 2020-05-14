/*
PFDEP - Project File Dependencies
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 110
vector<int> g[mxn],ind(mxn,0);

int main(){
int n,m;
cin>>n>>m;
int u,v,k;
while(m--){
    cin>>u>>k;
    while(k--){
        cin>>v;
        g[v].push_back(u);
        ind[u]++;
    }
}
for(int i=1; i<=n; ++i)
    sort(g[i].begin(),g[i].end());
int c=0;
priority_queue<int,vector<int>, greater<int> > q;
for(int i=1;i<n+1; ++i)
    if(!ind[i]) q.push(i);

vector<int> tpsort;
while(!q.empty()){
    u=q.top();
    q.pop();
    tpsort.push_back(u);
    for(int v:g[u]){
        if(ind[v]!=0){
            --ind[v];
            if(ind[v]==0) q.push(v);
        }
    }
}
int l=tpsort.size();
for(int i=0; i<l; ++i) cout<<tpsort[i]<<" ";

return 0;}
