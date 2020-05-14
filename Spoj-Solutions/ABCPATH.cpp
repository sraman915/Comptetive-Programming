/*
SOLUTION BY RAMAN SHARMA
http://www.spoj.com/problems/ABCPATH/
ABCPATH - ABC Path
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
int n,m,mx;
int vis[51][51];
int dir[][8]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
char a[51][51];


bool fine(int x,int y){
if(x<0||y<0||x>=n||y>=m)return 0;
return 1;
}

int rec(int x,int y,int z=1){
if(vis[x][y]!=-1)
    return vis[x][y];
int dx,dy;
mx=max(mx,z);
if(z==26) return z;
int temp=z;
for(int i=0; i<8&&z<26; ++i){
    temp=z;
    dx=x+dir[i][0];
    dy=y+dir[i][1];
    if(fine(dx,dy)&&a[dx][dy]==a[x][y]+1)
        temp=max(temp,rec(dx,dy,z+1));
}
vis[x][y]=temp;
}


int main(){
sp;
int i=0;
while(1){
    cin>>n>>m;
    ++i;
    if(n==0&&m==0) return 0;
    queue<pi> q;
    memset(vis,-1,sizeof vis);
     cout<<"Case "<<i<<": ";
    for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j){
            cin>>a[i][j];
    if(a[i][j]=='A')
    q.push({i,j});
    }
    mx=0;
    while(!q.empty()&&mx<26){
        rec(q.front().f,q.front().s);
        q.pop();
    }
    cout<<mx<<"\n";
}
return 0;}
