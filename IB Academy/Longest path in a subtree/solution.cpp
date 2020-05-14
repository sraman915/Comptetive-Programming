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

const long long mod=1000000007;

const int mx=65;
vector<int> g[mx];
int dp[mx][mx],ans=0,k;

void dfs(int v, int par){
	dp[v][0]=1;
	for(auto &it:g[v]){
		if(it==par)
			continue;
		dfs(it, v);
		for(int i=k;i>=0;i--){
			int val=dp[v][i];
			for(int j=0;i+j+1<=k;j++)
				dp[v][max(i, j+1)]=(dp[v][max(i, j+1)]+(val*dp[it][j])%mod)%mod;
		}
	}
	for(int i=0;i<=k;i++)
		ans=(ans+dp[v][i])%mod;
}

int doit(int A,vector<int> B,vector<int> C,int D){
    for(int i=0; i<=A; ++i)
        g[i].clear();
    memset(dp,0,sizeof dp);
    k=D;
    for(int i=0; i<B.size(); ++i){
        g[B[i]].push_back(C[i]);
        g[C[i]].push_back(B[i]);
    }
    ans=0;
    dfs(1,1);
    return ans;
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,k;
    cin>>n;
    int temp;
    cin>>temp;
    assert(temp==n-1);
    vector<int> u,v;
    for(int i=0; i<temp; ++i){
        int x;
        cin>>x;
        assert(x>=1&&x<=n);
        u.pb(x);
    }
    cin>>temp;
    assert(temp==n-1);
    for(int i=0; i<temp; ++i){
        int x;
        cin>>x;
        assert(x>=1&&x<=n);
        v.pb(x);
    }
    cin>>k;
    assert(k>=1&&k<n);
    assert(n>1&&n<=60);
    int ans=doit(n,u,v,k);
    cout<<ans<<"\n";
}
return 0;}
