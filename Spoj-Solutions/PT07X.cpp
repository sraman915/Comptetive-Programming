/*
PT07X - Vertex Cover
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mxn 100001
#define pb push_back
vector<int> g[mxn];
int dp[mxn][2];

void dfs(int s,int p){
dp[s][1]=1;
for(int i:g[s]){
    if(i==p) continue;
    dfs(i,s);
    dp[s][1]+=min(dp[i][0],dp[i][1]);
    dp[s][0]+=dp[i][1];}
}

int main(){
sp;
int n,x,y;
cin>>n;
for(int i=1; i<n; ++i){
    cin>>x>>y;
    g[x].pb(y);
    g[y].pb(x);
}
dfs(1,-1);
int r=min(dp[1][0],dp[1][1]);
if(!r) r=1;
cout<<r;

return 0;}
