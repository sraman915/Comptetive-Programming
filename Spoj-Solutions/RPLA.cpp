/*
RPLA - Answer the boss!
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 100000000
#define mod 1000000007
#define mxn 100010
#define pi pair<int,int>

int main(){
sp;
int t;
cin>>t;
for(int k=1; k<t+1; ++k){
        cout<<"Scenario #"<<k<<":\n";
    int n,m;
    cin>>n>>m;
    int in[n+1];
    memset(in,0,sizeof in);
    vector<int> g[n];
    int x,y;
    while(m--){
        cin>>x>>y;
        g[y].pb(x);
        in[x]++;
    }
    priority_queue<pi,vector<pi>,greater<pi> > q;
    queue<pi> qq;
    for(int i=0;i<n; ++i){
        if(in[i]==0){
            q.push(mp(1,i));
        qq.push(mp(1,i));
        }
    }
    x=1;
    while(!qq.empty()){
        x=qq.front().first;
        y=qq.front().second;
        qq.pop();
        for(int i:g[y]){
                --in[i];
            if(in[i]==0){
                q.push(mp(x+1,i));
                qq.push(mp(x+1,i));
            }
        }
    }
    while(!q.empty()){
        cout<<q.top().first<<" "<<q.top().second<<"\n";
        q.pop();
    }
    cout<<"\n";
}
return 0;}
