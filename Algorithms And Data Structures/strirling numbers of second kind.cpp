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

int dp[2005][2005];

//dp[n][r] states that number of ways to partition n objects into r non empty sets.
//Recurrence relation is S(n, r) = r*S(n-1, r) + S(n-1, r-1)
//Base Cases of stirling numbers:
//S(n,r) = 0 if r > n
//S(n,r) = 1 if r == n
//S(n,r) = NCR(n,2) if r = n - 1
//S(n,r) = NCR(n,3)+ 3 * NCR(n,4) if r == n-2
//S(n,r) = 1 if r == 1
//S(n,r) = 2^(n-1) - 1 if r == 2

void pre(){
    for(int i=1; i<=2000; ++i)
        for(int j=1; j<=i; ++j){
            if(i==1||j==1)
                dp[i][j]=1;
            else
                dp[i][j]=(1LL*j*dp[i-1][j]%mod+dp[i-1][j-1])%mod;
        }
}

int32_t main(){
sp;
    pre();
    cout<<dp[3][2];
    return 0;
}
