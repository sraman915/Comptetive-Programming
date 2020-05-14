/*
AKBAR - Akbar , The great
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main(){
    sp;
int t;
cin>>t;
while(t--){
    int n,r,m,i,j,x,y,z;
    cin>>n>>r>>m;
    vector<int> g[n+1],a(m),b(m);
    while(r--){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=0; i<m; ++i) cin>>a[i]>>b[i];
    y=1;
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    for(int i=0; i<m; ++i){
        x=a[i];
        if(vis[x]){
            y=0;
            break;
        }
          queue<pair<int,int> >q;
        vis[x]=i+1;
        q.push(make_pair(x,b[i]));
        while(1){
            if(q.empty()) break;
            x=q.front().first;
            z=q.front().second;
            if(z<=0) break;
            q.pop();
            for(int j:g[x]){
                if(!vis[j]){
                    vis[j]=i+1;
                    q.push(make_pair(j,z-1));
                }
                else{
                    if(vis[j]!=i+1)
                        y=0;
                }
            }
            if(!y) break;
        }
        if(!y) break;
    }
    for(int i=1; i<=n; ++i){
        if(vis[i]==0)
            y=0;
    }
    if(y) cout<<"Yes\n";
    else cout<<"No\n";

}
return 0;}
