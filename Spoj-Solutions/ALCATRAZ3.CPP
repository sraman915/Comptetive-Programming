/*
ALCATRAZ3 - THE HONEYCOMB MAZE
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
char a[102][102];
bool vis[102][102];
int dirc[][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
int ax,ay;
bool val(int x,int y){
if(x<1||y<1|x>n||y>m||a[x][y]=='*'||vis[x][y])
    return false;
return true;
}
bool dfs(int x,int y,int k){
vis[x][y]=1;
  for(int i=0; i<4; i++){
        int dx=x+dirc[i][0];
        int dy=y+dirc[i][1];
        if(dx==ax&&dy==ay&&k<2)
        return true;
        if(val(dx,dy))
        if(dfs(dx,dy,k-1))
            return true;
    }
    vis[x][y]=0;
 return false;
}
int main(){
int k,x,y;;
cin>>n>>m>>k>>x>>y;
for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
        cin>>a[i][j];
    }
}
ax=x,ay=y;
memset(vis,0,sizeof(vis));
if(dfs(x,y,k))
    cout<<"YES";
else
    cout<<"NO";
return 0;
}
