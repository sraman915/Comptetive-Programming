#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
//#define mod (long long)1000000007
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

const int N = 50005;
long long mod=1000000007;
vector<int> graph[N],g1[N];
long long dp[N][51];
int hcf[51][51];
int tc=0;

void pre(){
    if(tc)
        return;
    tc=1;
    for(int i=1; i<=50; ++i)
        for(int j=1; j<=50; ++j){
            int x=__gcd(i,j);
            hcf[i][j]=x;
    }
}

void clean(int n){
    for(int i=0; i<=n; ++i){
        graph[i].clear();
        for(int j=0; j<=50; ++j)
            dp[i][j]=0;
    }
    for(int i=0; i<=50; ++i)
        g1[i].clear();
}



void make_edges(int k){
    for(int i=1; i<=50; ++i)
        for(int j=1; j<=50; ++j){
            if(hcf[hcf[i][j]][k]>1){
                g1[i].push_back(j);
                //g1[j].push_back(i);
            }
    }
}

void dfs(int x,int parent){
    long long p[51];
    for(int i=1; i<=50; ++i)
        p[i]=1LL;
    for(auto &it:graph[x])
        if(it!=parent){
            dfs(it,x);
        for(int i=1; i<=50; ++i){
            long long sum=0;
            for(auto &it1:g1[i])
                sum=(sum+dp[it][it1])%mod;
            p[i]=(1LL*p[i]*sum)%mod;
        }
    }
    for(int i=1; i<=50;++i)
        dp[x][i]=p[i];
}

int solveit(int n,vector<vector<int>> &edges,int k){
    pre();
    clean(n);
    make_edges(k);
    for(auto &it:edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    dfs(1,0);
    long long ans=0;
    for(int i=1; i<=50;++i){
        ans=(ans+dp[1][i]);
        while(ans>=mod)
            ans-=mod;
    }
    return (int)(ans);
}


int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        assert(n>=1&&n<=50000);
        int m,tm;
        cin>>m>>tm;
        assert(m==n-1);
        assert(tm==2);
        vector<vector<int> > edges(m,vector<int>(2));
        for(int i=0; i<m; ++i){
            cin>>edges[i][0]>>edges[i][1];
            assert(edges[i][0]!=edges[i][1]);
            assert(edges[i][0]>=1&&edges[i][0]<=n);
            assert(edges[i][1]>=1&&edges[i][1]<=n);
        }
        cin>>k;
        assert(k>=1&&k<=50);
        int ans=solveit(n,edges,k);
        cout<<ans<<"\n";
    }
    return 0;
}
