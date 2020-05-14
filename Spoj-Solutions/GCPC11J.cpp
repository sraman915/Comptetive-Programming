/*
GCPC11J - Time to live
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pb push_back
#define mxn 100005
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
vector<int> g[mxn];
int d[mxn],vis[mxn],n;
int ans=-1,id=-1;
void bfs(int s){
memset(d,0,sizeof d);
memset(vis,0,sizeof vis);
d[s]=0;
vis[s]=1;
queue<int> q;
q.push(s);
int x;
while(!q.empty()){
    x=q.front();
    q.pop();
    for(int i:g[x]){
        if(!vis[i]){
            vis[i]=1;
            d[i]=d[x]+1;
            q.push(i);
        }
    }
}
for(int i=0; i<n; ++i)
    if(d[i]>ans){
        ans=d[i];
        id=i;}
}

int main(){
sp;
int t;
cin>>t;
while(t--){
    int x,y;
    cin>>n;
    for(int i=0; i<mxn; ++i)
        g[i].clear();
    for(int i=1; i<n; ++i){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    bfs(0);
    ans=-1;
    bfs(id);
    cout<<(ans+1)/2<<"\n";
    ans=-1,id=-1;
}
return 0;}
