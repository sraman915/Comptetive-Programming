/*
https://www.spoj.com/problems/HPFORF/
SOLUTION BY RAMAN SHARMA
HPFORF - HARRY POTTER AND THE FORBIDDEN FOREST
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

int dir[][4]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
char a[501][501];

bool check(int x,int y){
return (x>=1&&x<=n&&y>=1&&y<=m);
}

int main(){
sp;
int t;
cin>>t;
while(t--){
    int k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)cin>>a[i][j];
    pi par[n+1][m+1];
    int ans[n+1][m+1];
    memset(ans,0,sizeof ans);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m;++j)
    par[i][j]={i,j};
    int vis[n+1][m+1];
    memset(vis,0,sizeof vis);
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j){
        if(a[i][j]=='*'||vis[i][j])continue;
        vis[i][j]=1;
        queue<pi> q;
        q.push({i,j});
        int z=0;
        while(!q.empty()){
            pi p=q.front();
            q.pop();
            par[p.f][p.s]={i,j};
            int dx,dy;
            for(int i=0; i<4; ++i){
                dx=p.f+dir[i][0];
                dy=p.s+dir[i][1];
                if(check(dx,dy)){
                    if(a[dx][dy]=='*')++z;
                    else{
                        if(vis[dx][dy]==0){
                            vis[dx][dy]=1;
                            q.push({dx,dy});
                        }
                    }
                }
            }
        }
        ans[i][j]=z;
    }
int x,y;
while(k--){
    cin>>x>>y;
    cout<<ans[par[x][y].f][par[x][y].s]<<"\n";
}
}
return 0;
}
