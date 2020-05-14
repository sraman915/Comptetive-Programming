/*
HERDING - Herding
SOLUTION BY RAMAN SHARMA
*/

#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie|(NULL)
#define mxn 1001
char a[mxn][mxn];
int n,m;
bool check(int i,int j){
	if(i<0||j<0||i>=n||j>=m) return 0;
	return 1;
}

int main(){
	cin>>n>>m;
	for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>a[i][j];
	bool vis[n][m];
	memset(vis,0,sizeof vis);
	int x,y,x1,y1,dx,dy,x2,y2;
	int dir[][2]={{1,0},{0,1},{-1,0},{0,-1}};
	map<char,int> mm;
	mm['N']=2;
	mm['S']=0;
	mm['W']=3;
	mm['E']=1;
	int ans=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(!vis[i][j]){
				++ans;
				x=i,y=j;
				vis[x][y]=1;
				queue<pair<int,int> >q;
				q.push(make_pair(x,y));
				while(!q.empty()){
					x=q.front().first;
					y=q.front().second;
				//	cout<<x<<" "<<y<<"\n";
					vis[x][y]=1;
					q.pop();
					dx=x+dir[mm[a[x][y]]][0];
					dy=y+dir[mm[a[x][y]]][1];
					if(!vis[dx][dy]){
						vis[dx][dy]=1;
						q.push(make_pair(dx,dy));
						//cout<<dx<<" "<<dy<<"\n";
					}
					for(int k=0; k<4; ++k){
						x1=x+dir[k][0];
						y1=y+dir[k][1];
						if(check(x1,y1)){
							x2=x1+dir[mm[a[x1][y1]]][0];
							y2=y1+dir[mm[a[x1][y1]]][1];
							if(!vis[x1][y1]&&x2==x&&y2==y){
							q.push(make_pair(x1,y1));
						 }
						}
					}
					}
					}
			}
			}
	cout<<ans;
return 0;
}
