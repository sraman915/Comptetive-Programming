/*
SHPATH - The Shortest Path
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 10001
#define inf 10000000
#define mp make_pair
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
vector<pair<int,int> > g[mxn];
vector<int> d(mxn),vis(mxn,0);
void dijkstra(int s){
for(int i=0; i<mxn; ++i) d[i]=inf,vis[i]=0;
d[s]=0;
priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > q;
q.push(mp(0,s));
while(!q.empty()){
    s=q.top().second;
    q.pop();
    for(int i=0; i<g[s].size(); ++i){
        int y=g[s][i].second;
        int w=g[s][i].first;
        if(d[y]>d[s]+w){
            d[y]=d[s]+w;
            q.push(mp(d[y],y));
        }
    }
}
}
int main(){
sp;
int t;
cin>>t;
while(t--){
        for(int i=0; i<mxn; ++i) g[i].clear();
    int n;
    cin>>n;
    unordered_map<string,int> m;
    m.reserve(n+1);
    string s;
    int w,x,e;
     for(int i=1; i<n+1; ++i){
        cin>>s>>e;
        m[s]=i;
        while(e--){
            cin>>x>>w;
            g[i].push_back(mp(w,x));
        }
     }
     int r;
     cin>>r;
     string ss,tt;
     while(r--){
        cin>>ss>>tt;
        x=m[ss];
        e=m[tt];
        dijkstra(x);
        cout<<d[e]<<"\n";
     }
}
return 0;}
