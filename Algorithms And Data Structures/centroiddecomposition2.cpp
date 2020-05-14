#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define priority_queue pq
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 100001

vector<int> level(mxn),ans(mxn),par(mxn),subtree(mxn);
int dp[18][mxn];
set<int> g[mxn];
int c,n;

void dfs1(int x,int p){
    for(int i:g[x]){
        if(i!=p){
            level[i]=level[x]+1;
        dp[0][i]=x;
        dfs1(i,x);
    }
    }
    ans[x]=level[x];
}

void pre(){
    level[1]=0;
    dp[0][1]=0;
    dfs1(1,0);
    for(int i=1; i<17; ++i)
        for(int j=1; j<=n; ++j)
            dp[i][j]=dp[i-1][dp[i-1][j]];
}

void dfs2(int x,int p){
    subtree[x]=1;
    ++c;
    for(int i:g[x]){
        if(i!=p){
            dfs2(i,x);
        subtree[x]+=subtree[i];
        }
    }
}

int centroid(int x,int p){
    for(int i:g[x]){
        if(i!=p){
            if(subtree[i]>c)
                return centroid(i,x);
        }
    }
    return x;
}

void decompose(int x,int p){
    c=0;
    dfs2(x,p);
    c>>=1;
    int centre=centroid(x,p);
    par[centre]=p;
    for(int i:g[centre]){
        if(i!=p){
            g[i].erase(centre);
            decompose(i,centre);
        }
    }
    g[centre].clear();
}

int lca(int a,int b){
    if(level[a]>level[b])
        swap(a,b);
    int d=level[b]-level[a];
    for(int i=0; i<17; ++i){
        if((d>>i)&1)
            b=dp[i][b];
    }
    if(a==b)
        return a;
    for(int i=16; i>=0; --i){
        if(dp[i][a]!=dp[i][b]){
            a=dp[i][a];
            b=dp[i][b];
        }
    }
    return dp[0][b];
}

int dist(int a,int b){
    return level[a]+level[b]-2*level[lca(a,b)];
}

int query(int x){
    int y=x;
    int z=INT_MAX;
    while(x){
        z=min(z,ans[x]+dist(x,y));
        x=par[x];
    }
    return z;
}

void update(int x){
    int y=x;
    while(x){
        ans[x]=min(ans[x],dist(x,y));
        x=par[x];
    }
}

int32_t main(){
sp;
    int m,x,y,q;
    cin>>n>>q;
    m=n-1;
    while(m--){
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }
    pre();
    decompose(1,0);
    while(q--){
        cin>>x>>y;
        if(x&1)
            update(y);
        else
            cout<<query(y)<<"\n";
    }
    return 0;
}
