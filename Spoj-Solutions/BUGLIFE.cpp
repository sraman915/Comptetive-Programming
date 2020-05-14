/*
BUGLIFE-A BUG'S LIFE
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[2005],c(2005);
bool bfs(int s){
queue<int> q;
c[s]=1;
q.push(s);
while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=0; i<g[u].size(); ++i){
        int v=g[u][i];
        if(c[v]==-1){
            c[v]=1-c[u];
            q.push(v);
        }
        else if(c[v]==c[u])
            return false;
    }
}
return true;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int j=1; j<=t; ++j){
            for(int i=0; i<2005; ++i){
                g[i].clear();
                c[i]=-1;
            }
int n,m,x,y;
scanf("%d%d",&n,&m);
for(int i=0; i<m;++i){
        scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
}
y=1;
for(int i=1; i<=n; ++i){
    if(c[i]==-1){
       y=bfs(i);
        if(!y)
            break;}}
            printf("Scenario #%d:\n",j);
            if(y)
                printf("No suspicious bugs found!\n");
        else
                printf("Suspicious bugs found!\n");

    }
return 0;}
