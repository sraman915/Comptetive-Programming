/*
ALLIZWEL - ALL IZZ WELL
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
string s="ALLIZZWELL";
int n,m;
int vis[101][101];
char g[101][101];
bool check(int i,int j){
if(i<0||j<0||i>n-1||j>m-1)
    return 1;
return 0;
}
int floodfill(int i,int j,int k){
if(check(i,j))
    return 0;
if(k==9&&vis[i][j]==0&&s[k]==g[i][j])
    return 1;
if(vis[i][j]==1||s[k]!=g[i][j])
    return 0;
vis[i][j]=1;
if(floodfill(i,j+1,k+1)) return 1;
if(floodfill(i+1,j+1,k+1)) return 1;
if(floodfill(i-1,j+1,k+1)) return 1;
if(floodfill(i,j-1,k+1)) return 1;
if(floodfill(i+1,j-1,k+1)) return 1;
if(floodfill(i-1,j-1,k+1)) return 1;
if(floodfill(i+1,j,k+1)) return 1;
if(floodfill(i-1,j,k+1)) return 1;
vis[i][j]=0;
return 0;
}
int main(){
int t;
scanf("%d",&t);
while(t--){
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i)
        scanf("%s",&g[i]);
    int x=0;
      for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(g[i][j]=='A'){
              x=floodfill(i,j,0);
                if(x==1)
                    goto abc;
            }

        }
      }
abc:
    if(x==1)
        printf("YES\n");
    else
        printf("NO\n");
}

return 0;}
