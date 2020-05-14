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

int dp[505][505][3];
int n,m;
const int MOD = 1000000007;

int rec(int i,int C,int prev){
    if(C>m)
        return 0;
    if(i==n)
        return 1;
    auto &ans=dp[i][C][prev];
    if(ans!=-1)
        return ans;
    ans=rec(i+1,C+1,0);
    if(prev!=1)
        ans=(ans+rec(i+1,C,1))%MOD;
    if(prev!=2)
        ans=(ans+rec(i+1,C,2))%MOD;
    return ans%MOD;
}

int solve(int A,int B){
    n=A;
    m=B;
    for(int i=0; i<=A+1; ++i)
        for(int j=0; j<=B+1; ++j)
            for(int k=0; k<=2; ++k)
                dp[i][j][k]=-1;
    return rec(0,0,0);
}

int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    assert(n>=1&&n<=500);
    assert(m>=0&&m<=500);
    cout<<solve(n,m)<<"\n";
}
return 0;}
