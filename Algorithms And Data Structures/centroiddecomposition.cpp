#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define priority_queue pq
#define inf (ll)1e15
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 100010
#define mx2 1048579
int n;
vector<int> g[mxn],rankofnode(mxn),used(mxn),weight(mxn);

void dfs(int x,int p){
    weight[x]=1;
    for(int i:g[x]){
        if(!used[i]&&i!=p){
            dfs(i,x);
            weight[x]+=weight[i];
        }
    }
}

int  find(int x,int p,int w){
    for(int i:g[x]){
        if(i!=p&&used[i]==0){
            if(weight[i]>=w)
                return find(i,x,w);
        }
    }
    return x;
}

void solve(int x,int depth){
    dfs(x,0);
    int cur=find(x,0,weight[x]>>1);
    rankofnode[cur]=depth;
    used[cur]=1;
    for(int i:g[cur]){
        if(!used[i])
            solve(i,depth+1);
    }
}

int32_t main() {
sp;
    int x,y;
    cin>>n;
    for(int i=1; i<n; ++i){
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    solve(1,0);
    for(int i=1; i<=n; ++i)
        cout<<char((rankofnode[i]+65))<<" ";;
return 0;}
