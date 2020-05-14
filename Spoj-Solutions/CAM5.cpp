/*
CAM5 - prayatna PR
SOLUTION BY RAMAN SHRAMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 100001
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
vector<int> g[mxn],vis(mxn);

void dfs(int s){
vis[s]=1;
for(int i:g[s]){
    if(!vis[i]) dfs(i);
}
}

int main(){
sp;
int t;
cin>>t;
while(t--){
        for(int i=0; i<mxn; ++i){
            g[i].clear();
            vis[i]=0;
        }
    int n,e,x,y;
    cin>>n>>e;
    while(e--){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans=0;
    for(int i=0; i<n; ++i){
        if(!vis[i]){
            ++ans;
            dfs(i);
        }
    }
    cout<<ans<<"\n";
}

return 0;}
