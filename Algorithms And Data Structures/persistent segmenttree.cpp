#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 100005

vector<int> g[mxn];
int dp[19][mxn],level[mxn],a[mxn],n;
int l[16*mxn],r[16*mxn],tree[16*mxn],root[mxn],node=0;

int leaf(int y){
int p=++node;
l[p]=r[p]=0;
tree[p]=y;
return p;
}

int newp(int lef,int rig){
int p=++node;
l[p]=lef;
r[p]=rig;
return p;
}

int build(int le,int ri){
if(le==ri)return leaf(0);
int m=(le+ri)>>1;
return newp(build(le,m),build(m+1,ri));
}

int update(int i,int le,int ri,int p){
if(le==ri)return leaf(tree[i]+1);
int m=(le+ri)>>1;
if(p>=le&&p<=m)return newp(update(l[i],le,m,p),r[i]);
return newp(l[i],update(r[i],m+1,ri,p));
}

int query(int i,int le,int ri,int p){
if(!i)return 0;
if(le==ri)return tree[i];
int m=(le+ri)>>1;
if(p>=le&&p<=m)return query(l[i],le,m,p);
return query(r[i],m+1,ri,p);
}


void dfs(int x=1,int p=0){
dp[0][x]=p;
root[x]=update(root[p],1,n,a[x]);
for(int &i:g[x])
if(i!=p){
    level[i]=1+level[x];
    dfs(i,x);
}
}


int getp(int x,int k){
for(int i=0; i<19; ++i)
    if(k&(1<<i))x=dp[i][x];
return x;
}

int lca(int x,int y){
if(x==y)return x;
if(level[x]>level[y])
    swap(x,y);
y=getp(y,level[y]-level[x]);
for(int i=18; i>-1;--i)
if(dp[i][x]!=dp[i][y]){
    x=dp[i][x];
    y=dp[i][y];
}
return dp[0][x];
}



void pre(){
node=0;
root[0]=build(1,n);
memset(dp,-1,sizeof dp);
dfs();
for(int i=1; i<19; ++i)
    for(int j=1; j<=n; ++j)
    if(dp[i-1][j]!=-1)
    dp[i][j]=dp[i-1][dp[i-1][j]];
}

int get(int a,int k){
return query(root[a],1,n,k);
}

bool check(int x,int y,int c){
int z=lca(x,y);
//cout<<z<<"\t";
//cout<<x<<" "<<get(x,c)<<" "<<y<<" "<<get(y,c)<<" "<<z<<" "<<get(z,c)<<"\n";
int p=get(x,c)+get(y,c)-2*get(z,c)+(a[z]==c);
return (p>=1);
}

void clean(){
for(int i=0; i<=node; ++i)
    tree[i]=l[i]=r[i]=root[i]=0;
}

int main(){
//sp;
int q;
while(scanf("%d%d",&n,&q)!=EOF){
    int x,y,k;
    unordered_map<int,int> mp;
    for(int i=1; i<=n; ++i){
        scanf("%d",a+i);
        mp[a[i]];
    }
    x=0;
    clean();
    for(auto &it:mp)it.s=++x;
    for(int i=1; i<=n;++i)a[i]=mp[a[i]];
    for(int i=1; i<n; ++i){
        scanf("%d%d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    pre();
    while(q--){
        scanf("%d%d%d",&x,&y,&k);
        if(mp.find(k)==mp.end()){
            puts("NotFind\n");
            continue;
        }
        k=mp[k];
        if(check(x,y,k))puts("Find");
        else puts("NotFind");
    }
    for(int i=1; i<=n; ++i){
        g[i].clear();
        level[i]=0;
    }
    putchar('\n');
}
return 0;}
