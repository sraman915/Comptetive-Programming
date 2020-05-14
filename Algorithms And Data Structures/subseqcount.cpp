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

int32_t main() {
 sp;
    string a="RABBIT";
    string b;
    cin>>b;
    int n=b.size();
    int dp[6][n];
    memset(dp,0,sizeof dp);
    for(int i=0; i<6; ++i){
        for(int j=0; j<n; ++j){
            if(j)
                dp[i][j]=dp[i][j-1];
            if(!i){
                if(b[j]==a[0])
                    dp[i][j]+=1LL;
            }
            else{
                if(j&&b[j]==a[i])
                    dp[i][j]+=dp[i-1][j-1];
            }
        }
    }
    cout<<dp[5][n-1];
    return 0;
}
