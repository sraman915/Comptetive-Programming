/*
SOLUTION BY RAMAN SHARMA
TFRIENDS - True Friends
https://www.spoj.com/problems/TFRIENDS/
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
#define pi pair<double,double>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

vector<int> g[101],r[101],topsort;
int vis[101],c=0;

void dfs(int x){
vis[x]=1;
for(auto &it:g[x])
    if(!vis[it])dfs(it);
topsort.pb(x);
}

void dfs1(int x){
vis[x]=0;
for(auto &it:r[x])
    if(vis[it])dfs1(it);
}

int main(){
sp;
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    char ch;
    c=0;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j){
        cin>>ch;
        if(ch=='Y')g[i].pb(j),r[j].pb(i);
    }
    for(int i=1; i<=n; ++i)
        if(!vis[i])dfs(i);
        int x;
    while(!topsort.empty()){
        x=topsort.back();
        topsort.pop_back();
        if(vis[x]){
            ++c;
            dfs1(x);
        }
    }
    cout<<c<<"\n";
for(int i=1; i<=n; ++i){
    g[i].clear();
    r[i].clear();
    vis[i]=0;
}
}
return 0;}

