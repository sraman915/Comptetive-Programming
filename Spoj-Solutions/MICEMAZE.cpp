/*
MICEMAZE - Mice and Maze
SOLUTION BY RAMAN SHARMA
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false)cin.tie(NULL),cout.tie(NULL)
#define mxn 110
#define inf 100000
int g[mxn][mxn];
int main(){
	int n,e,t,m,ans=0,x,y,w;
	cin>>n>>e>>t>>m;
	for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) g[i][j]=inf;
	while(m--){
		cin>>x>>y>>w;
		g[x][y]=w;
	}
	for(int i=0; i<=n; ++i) g[i][i]=0;
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n; i++)
		if(g[i][e] <= t)
			++ans;
	cout<<ans;
	return 0;
}
