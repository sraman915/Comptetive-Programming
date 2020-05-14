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


int maxProfit(vector<int>& prices,int k) {
    if(k==0 || prices.size() == 0)
        return 0;
    int max_profit = 0;
    if(k >= prices.size()/2) {
        for(int i = 1;i < prices.size();i++) {
            max_profit += max(prices[i] - prices[i-1], 0LL);
        }
        return max_profit;
    }
    vector<vector<int>> dp(k+1, vector<int>(prices.size() + 1, 0LL));

    for(int i=1;i<=k;i++) {
        int maxDiff = -prices[0];
        for(int j = 2;j <= prices.size();j++) {
            dp[i][j] = max(dp[i][j-1], prices[j-1] + maxDiff);
            maxDiff = max(maxDiff, dp[i-1][j] - prices[j-1]);
        }
    }
    return dp[k][prices.size()];
}

int solveit(vector<int> &prices,int k){
    return maxProfit(prices,k);
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
assert(n>=2&&n<=500);
vector<int> a(n);
for(int i=0; i<n; ++i){
cin>>a[i];
assert(a[i]>=0&&a[i]<=1000000);
}
int k;
cin>>k;
assert(k>=0&&k<=1000000000);
int ans=solveit(a,k);
cout<<ans<<"\n";
}
return 0;}
