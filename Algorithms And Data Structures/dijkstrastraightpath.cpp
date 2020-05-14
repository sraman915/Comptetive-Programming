#include<bits/stdc++.h>
using namespace std;
#define mxn 1001
#define inf 100000000
int dir[][2]={{-1,0},{0,-1},{1,0},{0,1}};
char a[mxn][mxn];
int n,m;
int di[mxn][mxn][4];

struct node{
int x,y,d;
node(int p,int q,int r){
x=p,y=q,d=r;
}
};

bool check(int i,int j){
if(i<0||j<0||i>=n||j>=m) return 0;
if(a[i][j]=='*') return 0;
return 1;
}

int main(){
int sx,sy,ex,ey,k=0;
cin>>n>>m;
for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
        cin>>a[i][j];
        for(k=0; k<4; ++k)
            di[i][j][k]=inf;
    if(a[i][j]=='V')
        sx=i,sy=j;
    if(a[i][j]=='H')
        ex=i,ey=j;
}
}
queue<node> q;

for(k=0; k<4; ++k){
    di[sx][sy][k]=0;
    q.push(node(sx,sy,k));
}
int xx,yy,w,dd,dx,dy;
while(!q.empty()){
    node p=q.front();
    q.pop();
    xx=p.x;
    yy=p.y;
    dd=p.d;
    for(k=0; k<4; ++k){
        dx=xx+dir[k][0];
        dy=yy+dir[k][1];
        if(check(dx,dy)){
            if(di[dx][dy][k]>di[xx][yy][dd]+(dd!=k)){
                di[dx][dy][k]=di[xx][yy][dd]+(dd!=k);
                q.push(node(dx,dy,k));
            }
        }
    }
}
int r=inf;
for(k=0; k<4; ++k){
    if(di[ex][ey][k]==inf) continue;
r=min(r,di[ex][ey][k]);
}
cout<<(r==inf?-1:r);

return 0;}
