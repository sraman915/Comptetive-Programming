/*
TOPOSORT - Topological Sorting
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 10001
vector<int> g[mxn],ind(mxn,0);

int main(){
int n,m;
scanf("%d%d",&n,&m);
int u,v;
while(m--){
    scanf("%d%d",&u,&v);
    g[u].emplace_back(v);
    ind[v]++;
}
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
++c;}
if(c!=n){
    printf("Sandro fails.");
    return 0;
}
int l=tpsort.size();
for(int i=0; i<l; ++i) printf("%d ",tpsort[i]);

return 0;}
