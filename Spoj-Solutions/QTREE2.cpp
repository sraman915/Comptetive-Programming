/*
    SOLUTION BY RAMAN SHARMA
    QTREE2 - Query on a tree II
    https://www.spoj.com/problems/QTREE2/

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

vector<int> g[mxn];
int dp[mxn][20];
int subsize[mxn],depth[mxn];
int chainHead[mxn],chainPos[mxn],chainSize[mxn],chainInd[mxn],chainNo=0,l,ptr;
int posInBase[mxn],baseArray[mxn];
int a[mxn];
int n;

int tree[4*mxn];


void build(int i, int l, int r){
    if(l==r){
        tree[i]=baseArray[l];
        return;
    }
    int m=(l+r)>>1;
    build(i+i+1, l, m), build(2*i+2, m+1, r);
    tree[i]=(tree[i+i+1]+tree[i+i+2]);
}

void update(int i,int l,int r,int x,int y){
    if(l==r){
        tree[i]=y;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m)
        update(i+i+1,l,m,x,y);
    else
        update(i+i+2,m+1,r,x,y);
    tree[i]=(tree[i+i+1]+tree[i+i+2]);
}

int query(int i, int l, int r, int ql, int qr){
    if(ql>qr)
        swap(ql, qr);
    if(ql<=l && r<=qr)
        return tree[i];
    if(qr<l||r<ql||l>r)
        return 0;
    int m=(l+r)>>1;
    int f=(query(2*i+1, l, m, ql, qr)+ query(2*i+2, m+1, r, ql, qr));
    return f;
}

int lca(int u, int v){
    if(depth[u]<depth[v])
        swap(u,v);
    int diff=depth[u]-depth[v];
    for(int i=0; i<l; ++i)
        if((diff>>i)&1)
            u=dp[u][i];
    if(u==v)
        return u;
    for(int i=l-1; i>=0; --i)
        if(dp[u][i] != dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    return dp[u][0];
}

int dfs(int node, int p, int d=0){
    dp[node][0] = p;
    depth[node]=d;
    int sum=1;
    for(auto &u:g[node])
        if(u!=p)
            sum+=dfs(u,node,d+1);
    subsize[node]=sum;
    return sum;
}


void hld(int node, int p){
    if(chainHead[chainNo]==-1)
        chainHead[chainNo]=node;
    chainInd[node]=chainNo;
    chainPos[node]=chainSize[chainNo];
    chainSize[chainNo]++;
    posInBase[node]=ptr;
	baseArray[ptr++]=a[node];
    int sc=-1,mx=0;
    for(auto &it:g[node])
        if(it!=p&&mx<subsize[it]){
            sc=it;
            mx=subsize[it];
        }
    if(sc!=-1)
        hld(sc, node);
    for(auto it:g[node])
        if(it!=p && it!=sc){
            chainNo++;
            hld(it, node);
        }
}

int query_hld2(int u, int v){
    if(u==v)
        return 0;
    int ans=0;
    while(chainInd[u] != chainInd[v]){
        ans+=query(0, 0, ptr-1, posInBase[u], posInBase[chainHead[chainInd[u]]]);
        u=dp[chainHead[chainInd[u]]][0];
    }
    if(u!=v)
        ans+=query(0, 0, ptr-1, posInBase[u], posInBase[v]+1);
    return ans;
}

int query_hld(int u, int v){
    if(u==v)
        return 0;
    int x = lca(u, v);
    int ans;
    int x1=query_hld2(u,x);
    int x2=query_hld2(v,x);
    ans=x1+x2;
   // cout<<v<<" "<<x1<<" "<<x2<<" "<<x3<<"\n";
    return ans;
}


vector<pii> edges;

void init(){
    l=ceil(1.0*log2(n));
    edges.clear();
    for(int i=0; i<=4*n; ++i)
        tree[i]=0;
    chainNo=0;
    ptr=0;
    for(int i=0; i<=n; ++i){
        g[i].clear();
        depth[i]=0;
        subsize[i]=0;
        chainHead[i]=-1;
        chainInd[i]=0;
        chainSize[i]=0;
        chainPos[i]=0;
        posInBase[i]=0;
        baseArray[i]=0;
        for(int j=0; j<l; ++j)
            dp[i][j]=-1;
    }
}


void pre(){
    dfs(0,-1);
    for(int i=1; i<l; ++i)
        for(int j=0; j<n; ++j)
            if(dp[j][i-1]!=-1)
                dp[j][i]=dp[dp[j][i-1]][i-1];

    for(auto &it:edges){
        if(depth[it.first]>depth[it.second.first])
            swap(it.first,it.second.first);
        a[it.second.first]=it.second.second;
    }

    hld(0,-1);
    build(0,0,ptr-1);
}

int kthnode(int x,int y,int k){
    if(k==1)
        return x+1;
    int z=lca(x,y);
    if(depth[x]-depth[z]+1>=k){
        --k;
        for(int i=l-1; i>=0; --i)
            if(k&(1<<i))
                x=dp[x][i];
        return x+1;
    }
    k-=(depth[x]-depth[z]+1);
    int tot=depth[y]-depth[z];
    k=tot-k;
    for(int i=l-1; i>=0; --i)
        if(k&(1<<i))
            y=dp[y][i];
    return y+1;
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        init();
        for(int i=1; i<n; ++i){
            int x,y,w;
            cin>>x>>y>>w;
            --x;
            --y;
            edges.push_back({x,{y,w}});
            g[x].push_back(y);
            g[y].push_back(x);
        }
        pre();
        string c;
        int x,y;
        while(1){
            cin>>c;
            if(c[1]=='O')
                break;
            cin>>x>>y;
            if(c[0]=='K'){
                int k;
                cin>>k;
                cout<<kthnode(x-1,y-1,k)<<"\n";
            }
            else
                cout<<query_hld(x-1,y-1)<<"\n";
        }
    }
    return 0;
}
