/*
SOLUTION BY RAMAN SHARMA
https://www.spoj.com/problems/DISQUERY/
DISQUERY - Distance Query

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
#define pi pair<int,ll>
#define pii pair<int,pi>
#define pb push_back
#define mxn 100005
vector<pi> g[mxn];
int par[mxn],level[mxn],dp[18][mxn],mn[18][mxn],mx[18][mxn];
int n;


void dfs(int x,int p=0){
par[x]=p;
dp[0][x]=p;
for(auto &it:g[x])
if(it.f!=p){
    mn[0][it.f]=it.s;
    mx[0][it.f]=it.s;
    level[it.f]=1+level[x];
    dfs(it.f,x);
}
}

int getp(int x,int k){
for(int i=0; i<18; ++i){
    if(k&(1<<i))
        x=dp[i][x];
}
return x;
}

int lca(int x,int y){
if(level[x]>level[y])swap(x,y);
y=getp(y,level[y]-level[x]);
if(x==y)return x;
for(int i=17;i>=0;i--){
    if(dp[i][x]!=dp[i][y]){
        x=dp[i][x];
        y=dp[i][y];
    }
}
return par[x];
}


void pre(){
for(int i=0; i<18; ++i)
    for(int j=1; j<=n; ++j){
            dp[i][j]=-1;
           mn[i][j]=INT_MAX;
           mx[i][j]=INT_MIN;
    }
dfs(1);
for(int i=1; i<18; ++i)
    for(int j=1; j<=n; ++j)
if(dp[i-1][j]!=-1){
    dp[i][j]=dp[i-1][dp[i-1][j]];
    mn[i][j]=min(mn[i-1][j],mn[i-1][dp[i-1][j]]);
    mx[i][j]=max(mx[i-1][j],mx[i-1][dp[i-1][j]]);
}
}

pi getminmax(int x,int y){
int x1=INT_MAX,x2=INT_MIN;
for(int i=17; i>=0;--i){
    if(level[y]-(1<<i)>=level[x]){
        x1=min(x1,mn[i][y]);
        x2=max(x2,mx[i][y]);
        y=dp[i][y];
    }
}
return {x1,x2};
}

pi ans(int x,int y){
int z=lca(x,y);
pi p1=getminmax(z,x);
pi p2=getminmax(z,y);
return {min(p1.f,p2.f),max(p1.s,p2.s)};
}


int main(){
sp;
cin>>n;
int x,y;
for(int i=1; i<n; ++i){
        int w;
    cin>>x>>y>>w;
    g[x].pb({y,w});
    g[y].pb({x,w});
}
pre();
int q;
cin>>q;
while(q--){
    cin>>x>>y;
    if(level[x]>level[y])swap(x,y);
    pi p=ans(x,y);
    cout<<p.f<<" "<<p.s<<"\n";
}
return 0;}
