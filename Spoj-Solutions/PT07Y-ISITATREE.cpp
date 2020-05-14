/*
IS IT A TREE OR NOT-PT07Y
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[10001];
bool vis[10001];
void dfs(int s){
vis[s]=1;
for(int i=0; i<g[s].size(); ++i){
    if(!vis[g[s][i]]){
            dfs(g[s][i]);}
}
}
int main(){
int n,m,x,y;
memset(vis,0,sizeof(vis));
scanf("%d%d",&n,&m);
for(int i=0; i<m;++i){
        scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
}
y=1;
dfs(1);
for(int i=1; i<=n; ++i){
    if(!vis[i]){
        y=0;
        break;}
}
if(m!=n-1)
    y=0;
if(y)
    printf("YES");
else
    printf("NO");

return 0;}
