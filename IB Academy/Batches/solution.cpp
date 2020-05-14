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
int a[N],vis[N];
int sum=0;

void make_graph(int n,vector<vector<int> > &edges,vector<int> &strength){
    for(int i=0; i<=n; ++i){
        g[i].clear();
        vis[i]=0;
    }
    for(auto &it:edges){
        g[it[0]].push_back(it[1]);
        g[it[1]].push_back(it[0]);
    }
    for(int i=0; i<strength.size(); ++i)
        a[i+1]=strength[i];
}

void dfs(int x){
    sum+=a[x];
    vis[x]=1;
    for(auto &it:g[x])
        if(!vis[it])
            dfs(it);
}

int solve(int A,vector<int> &B,vector<vector<int> > &C,int D){
    make_graph(A,C,B);
    assert(A==B.size());
    int ans=0;
    for(int i=1; i<=A; ++i){
        if(!vis[i]){
            sum=0;
            dfs(i);
            if(sum>=D)
                ++ans;
        }
    }
    return ans;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=100000);
    int tn;
    cin>>tn;
    assert(tn==n);
    vector<int> B(n);
    for(int i=0; i<n; ++i){
        cin>>B[i];
        assert(B[i]>=1&&B[i]<=1000);
    }
    int m,tm;
    cin>>m>>tm;
    assert(tm==2);
    vector<vector<int> > C(m,vector<int> (2));
    for(int i=0; i<m; ++i){
        cin>>C[i][0]>>C[i][1];
        assert(C[i][0]!=C[i][1]);
        assert(C[i][1]>=1&&C[i][1]<=n);
        assert(C[i][0]>=1&&C[i][0]<=n);
    }
    int D;
    cin>>D;
    assert(D>=1&&D<=1000000000);
    int ans=solve(n,B,C,D);
    cout<<ans<<"\n";
}
return 0;}

