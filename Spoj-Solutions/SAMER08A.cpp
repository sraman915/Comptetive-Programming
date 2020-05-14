/*
SAMER08A - Almost Shortest Path
SOLUTION BY RAMAN SHARMA
*/
#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define pc putchar_unlocked
#define gc getchar_unlocked
#define pb push_back
#define inf 100000000

inline int read_in(){
	register char ch;
	int x=0;
	ch=gc();
	while(ch<'0'||ch>'9')
	ch=gc();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=gc();
	}
	return x;
}

int main(){
while(1){
	int n,m,s,d;
	n=read_in(),m=read_in();
	if(n==0&&m==0)
	break;
	s=read_in(),d=read_in();
	vector<pi> g[n+1];
	int w,x,y;
	while(m--){
		x=read_in(),y=read_in(),w=read_in();
		g[x].pb(mp(w,y));
	}
	int dis[n+1];
	bool vis[n+1],mark[n+1][n+1];
	memset(vis,0,sizeof vis);
	memset(mark,0,sizeof mark);
	for(int i=0; i<=n; ++i) dis[i]=inf;
	dis[s]=0;
	vector<int> del[n+1];
	priority_queue<pi,vector<pi>,greater<pi > > q;
	q.push(mp(0,s));
	while(!q.empty()){
		x=q.top().second;
		q.pop();
		for(int i=0; i<g[x].size(); ++i){
		w=g[x][i].first;
		y=g[x][i].second;
		if(dis[y]>dis[x]+w){
			dis[y]=dis[x]+w;
			q.push(mp(dis[y],y));
			del[y].clear();
			del[y].pb(x);
		}
		else if(dis[y]==dis[x]+w)
		del[y].pb(x);
		}}
		if(dis[d]==inf){
			cout<<"-1\n";
			continue;
		}
		queue<int> qq;
		qq.push(d);
		vis[d]=1;
		while(!qq.empty()){
			x=qq.front();
			qq.pop();
			for(int i=0; i<del[x].size(); ++i){
			y=del[x][i];
			mark[y][x]=1;
			if(!vis[y]){
				vis[y]=1;
				qq.push(y);}}}
		int dis2[n+1];
		for(int i=0; i<n+1; ++i) dis2[i]=inf;
		dis2[s]=0;
		q.push(mp(0,s));
		while(!q.empty()){
			x=q.top().second;
			q.pop();
			for(int i=0; i<g[x].size(); ++i){
				w=g[x][i].first;
				y=g[x][i].second;
				if(!mark[x][y]&&dis2[x]+w<dis2[y]){
					dis2[y]=dis2[x]+w;
					q.push(mp(dis2[y],y));
				}
			}
		}
	if(dis2[d]==inf)
	cout<<"-1\n";
	else cout<<dis2[d]<<"\n";
}

return 0;}
