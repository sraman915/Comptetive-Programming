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
#define mxn 500005

const int N =100005;
vector<int> g[N];
vector<int> subtreeXor(N);
int vis[N];
int count1=0;
int c=0;

void clean(int n){
    for(int i=0; i<n; ++i){
        g[i].clear();
        subtreeXor[i]=0;
    }
}

void makeGraph(vector<vector<int> > &edges){
    for(auto &it:edges){
        int x=it[0];
        int y=it[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

void check(int x){
    vis[x]=c;
    ++count1;
    for(auto &it:g[x])
        if(vis[it]!=c)
            check(it);
}

void dfs(int x,int parent,vector<int> &a){
    subtreeXor[x]=a[x];
    for(auto &it:g[x]){
        if(it!=parent){
            dfs(it,x,a);
            subtreeXor[x]^=subtreeXor[it];
        }
    }
}

vector<int> solveit(int n,vector<int> &a,vector<vector<int> > &edges){
    clean(n);
    makeGraph(edges);
    check(0);
    assert(count1==n);
    dfs(0,-1,a);
    int maxXor=-1;
    int maxXorCount=0;
    for(int i=0; i<n; ++i){
        if(maxXor<subtreeXor[i]){
            maxXor=subtreeXor[i];
            maxXorCount=1;
        }
        else if(maxXor==subtreeXor[i])
            maxXorCount=maxXorCount+1;
    }
    assert(maxXor>=0&&maxXor<=INT_MAX);
    assert(maxXorCount>0);
    vector<int> ans(2);
    ans[0]=maxXor;
    ans[1]=maxXorCount;
    return ans;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    ++c;
    count1=0;
    int n;
    cin>>n;
    assert(n>=1&&n<=100000);
    int tempn;
    vector<int> a(n);
    cin>>tempn;
    assert(tempn==n);
    for(int i=0; i<n; ++i){
    cin>>a[i];
    assert(a[i]>=0&&a[i]<=1000000000);
    }
    vector<vector<int> > edges(n-1,vector<int>(2));
    int m,tempm;
    cin>>m>>tempm;
    assert(m==n-1);
    assert(tempm==2);
    for(int i=0; i<m; ++i){
    cin>>edges[i][0];
    cin>>edges[i][1];
    assert(edges[i][0]!=edges[i][1]);
    assert(edges[i][0]>=0&&edges[i][0]<n);
    assert(edges[i][1]>=0&&edges[i][1]<n);
    }
    vector<int> ans=solveit(n,a,edges);
    for(auto &it:ans)cout<<it<<" ";
    cout<<"\n";
}
return 0;}
