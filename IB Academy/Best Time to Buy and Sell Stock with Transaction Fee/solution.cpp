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

int solveit(vector<int> &a,int fee){
    int n=a.size();
    int dp[n] = {0};
    int max_prof = dp[0] - a[0] - fee;
    for(int i = 1; i<n; i++){
        dp[i] = max(dp[i-1], max_prof + a[i]);
        max_prof = max(max_prof, dp[i] - a[i] - fee);
    }
    return dp[n-1];
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
    assert(n>=1&&n<=50000);
    vector<int> a(n);
    for(int i=0; i<n; ++i){
    cin>>a[i];
    assert(a[i]>=1&&a[i]<=50000);
    }
    int fee;
    cin>>fee;
    assert(fee>=0&&fee<=50000);
    int ans=solveit(a,fee);
    cout<<ans<<"\n";
}
return 0;}

