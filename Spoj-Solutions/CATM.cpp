/*
CATM - The Cats and the Mouse
SOLUTION BY RAMAN SHARMA
*/

#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mxn 101
#define inf 1000000
int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int ms[mxn][mxn],c1[mxn][mxn],c2[mxn][mxn];

bool check(int i,int j){
	return (i>0&&j>0&&i<=n&&j<=m);
}

void bfs1(int x,int y){
	for(int i=0; i<=n; ++i) for(int j=0; j<=m; ++j) ms[i][j]=inf;
	ms[x][y]=0;
	queue<pair<int,int> > q;
	int dx,dy;
	q.push(make_pair(x,y));
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			dx=x+dir[i][0];
			dy=y+dir[i][1];
			if(check(dx,dy)){
				if(ms[dx][dy]>ms[x][y]+1){
				q.push(make_pair(dx,dy));
				ms[dx][dy]=ms[x][y]+1;
				}
			}
		}
	}
}
void bfs2(int x,int y){
	for(int i=0; i<=n; ++i) for(int j=0; j<=m; ++j) c1[i][j]=inf;
	c1[x][y]=0;
	queue<pair<int,int> > q;
	int dx,dy;
	q.push(make_pair(x,y));
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			dx=x+dir[i][0];
			dy=y+dir[i][1];
			if(check(dx,dy)){
				if(c1[dx][dy]>c1[x][y]+1){
				q.push(make_pair(dx,dy));
				c1[dx][dy]=c1[x][y]+1;
				}
			}
		}
	}
}
void bfs3(int x,int y){
	for(int i=0; i<=n; ++i) for(int j=0; j<=m; ++j) c2[i][j]=inf;
	c2[x][y]=0;
	queue<pair<int,int> > q;
	int dx,dy;
	q.push(make_pair(x,y));
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			dx=x+dir[i][0];
			dy=y+dir[i][1];
			if(check(dx,dy)){
				if(c2[dx][dy]>c2[x][y]+1){
				q.push(make_pair(dx,dy));
				c2[dx][dy]=c2[x][y]+1;

				}
			}
		}
	}
}
int main(){
	sp;
	cin>>n>>m;
	int mx,my,c1x,c1y,c2x,c2y;
	int t;
	cin>>t;
	while(t--){
	cin>>mx>>my>>c1x>>c1y>>c2x>>c2y;
	bfs1(mx,my);
	bfs2(c1x,c1y);
	bfs3(c2x,c2y);
	int y=0;
	for(int i=1; i<=n; ++i){
		if((ms[i][1]<c1[i][1])&&(ms[i][1]<c2[i][1]))
			y=1;
		if((ms[i][m]<c1[i][m])&&(ms[i][m]<c2[i][m]))
			y=1;
	}
		for(int i=1; i<=m; ++i){
		if((ms[1][i]<c1[1][i])&&(ms[1][i]<c2[1][i]))
			y=1;
		if((ms[n][i]<c1[n][i])&&(ms[n][i]<c2[n][i]))
            y=1;
	}
	cout<<"\n";
	if(!y)
	cout<<"NO\n";
            else cout<<"YES\n";

	}
	return 0;
}
