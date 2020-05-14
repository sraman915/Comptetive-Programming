/*
LONGEST PATH IN A TREE-PT07Z
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[100001],d(100005);
bool vis[100005];
int dfs(int s){
vis[s]=1;
int m1=0,m2=0;
for(int i=0; i<g[s].size(); ++i){
    if(!vis[g[s][i]]){
        int m=dfs(g[s][i]);
        if(m>m1){
            m2=m1,m1=m;
        }
        else if(m>m2)
            m2=m;
    }
}
d[s]=m1+m2;
return m1+1;}
int main(){
int n,x,y;
cin>>n;
for(int i=0; i<n-1; ++i){
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
}
dfs(1);
int ans=0;
for(int i=0; i<=n; ++i){
    ans=max(ans,d[i]);
}
cout<<ans;
return 0;
}
