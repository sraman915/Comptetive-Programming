/*
UCV2013H - Slick
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define ll long long
#define inf 100000000
#define mxn 300
int n,m;
int a[mxn][mxn];
bool check(int i,int j){
if(i<0||j<0||i>n-1||j>m-1)
    return 0;
    if(a[i][j]!=1) return 0;
return 1;
}
int main(){
sp;
while(1){
cin>>n>>m;
if(n==0&&m==0)
    return 0;
int v[n*m+10],vis[n][m];
memset(v,0,sizeof v);
memset(vis,0,sizeof vis);
queue<pi> q;
for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
            cin>>a[i][j];
if(a[i][j]==1)
    q.push(mp(i,j));}}

queue<pi> qq;
int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
int x,y,dx,dy,xx,yy;
while(!q.empty()){
    x=q.front().first;
    y=q.front().second;
    q.pop();
    if(vis[x][y]) continue;
    vis[x][y]=1;
    qq.push(mp(x,y));
    int p=1;
    while(!qq.empty()){
        xx=qq.front().first;
        yy=qq.front().second;
        qq.pop();
        for(int i=0; i<4; ++i){
            dx=xx+dir[i][0];
            dy=yy+dir[i][1];
            if(check(dx,dy)&&vis[dx][dy]==0){
                ++p;
                vis[dx][dy]=1;
                qq.push(mp(dx,dy));
            }
        }
    }
    v[p]+=1;
}
int sz=0;
for(int i=0; i<n*m+1; ++i){
    if(v[i])
        sz+=v[i];
}
cout<<sz<<"\n";
for(int i=1; i<n*m+1; ++i){
    if(v[i])
        cout<<i<<" "<<v[i]<<"\n";

}
}
return 0;}
