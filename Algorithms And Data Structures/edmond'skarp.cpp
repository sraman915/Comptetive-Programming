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
vector<int> g[mxn];
int cap[101][101],parent[101];
int s,t;


int bfs(){
memset(parent ,0,sizeof parent);
queue<int> q1;
queue<int> q2;
q1.push(s);
q2.push(inf);
int x,y,w,mn=0;
while(!q1.empty()){
    x=q1.front();
    q1.pop();
    w=q2.front();
    q2.pop();
    for(int i:g[x]){
        if(parent[i]==0&&cap[x][i]>0){
            q1.push(i);
            q2.push(min(w,cap[x][i]));
            parent[i]=x;
            if(i==t){
                mn=min(w,cap[x][i]);
                break;
            }
        }
    }
}
if(mn==0) return mn;
x=t;
while(x!=s){
    cap[parent[x]][x]-=mn;
    cap[x][parent[x]]+=mn;
    x=parent[x];
}
return mn;
}

int flow(){
int x=0;
int y=0;
while(1){
    y=bfs();
    if(y<=0) break;
    x+=y;
}
return x;
}


int main(){
sp;
int n,m;
cin>>n>>m;
int u,v,w;
for(int i=1; i<=m; ++i){
    cin>>u>>v>>w;
    g[u].pb(v);
    cap[u][v]=w;
}
cin>>s>>t;
cout<<flow();
return 0;}
