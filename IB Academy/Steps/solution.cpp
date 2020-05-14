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

const int N = 100005;
long long dp[N][21];
const int MOD = 1000000007;

int tc=0;

void pre(){
    if(tc)
        return;
    tc=1;
    dp[1][0]=1;
    dp[2][0]=2;
    dp[3][0]=3;
    dp[3][1]=1;
    for(int i=4; i<N; ++i)
        for(int j=0; j<21; ++j){
            if(j==0){
                dp[i][j]=dp[i-1][0]+dp[i-2][0];
                while(dp[i][j]>=MOD)
                    dp[i][j]-=MOD;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i-2][j]+dp[i-3][j-1];
                while(dp[i][j]>=MOD)
                    dp[i][j]-=MOD;
            }
        }
}


int solveit(int n,int k){
    pre();
    int ans=0;
    for(int i=0; i<=k; ++i){
        ans=(ans+dp[n][i]);
        while(ans>=MOD)
            ans-=MOD;
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
    int n,k;
    cin>>n>>k;
    assert(n>=1&&n<=100000);
    assert(k>=0&&k<=20);
    int ans=solveit(n,k);
    cout<<ans<<"\n";
}
return 0;}
