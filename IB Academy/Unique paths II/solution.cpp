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

long long dp[505][505];
const int MOD = 1000000007;

int uniquePathsWithObstacles(vector<vector<int>>& A) {
    int n=A.size();
    if(n==0)
        return 0;
    int m=A[0].size();
    if(m==0)
        return 0;
    if(A[n-1][m-1]||A[0][0])
        return 0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            dp[i][j]=0;
    dp[0][0]=1LL;
    for(int i=1; i<n; ++i)
        if(A[i][0]==0)
            dp[i][0]=dp[i-1][0];
    for(int i=1; i<m; ++i)
        if(A[0][i]==0)
            dp[0][i]=dp[0][i-1];
    for(int i=1; i<n;++i)
        for(int j=1; j<m; ++j)
            if(A[i][j]==0)
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
    return dp[n-1][m-1];
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    assert(n>=1&&n<=500);
    assert(m>=1&&m<=500);
    vector<vector<int> > A(n,vector<int> (m));
    for(int i=0; i<n; ++i)
        for(int j=0;j<m;++j){
        cin>>A[i][j];
        assert(A[i][j]>=0&&A[i][j]<=1);
        }
    int ans=uniquePathsWithObstacles(A);
    cout<<ans<<"\n";
}
return 0;}
