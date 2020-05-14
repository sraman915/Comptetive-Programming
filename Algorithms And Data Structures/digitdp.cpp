#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005


vector<int> dig(int n){
    vector<int> v;
    while(n){
        v.push_back(n % 10);
        n /= 10;
    }
    return v;
}

int dp[11][100][100][2];

vector<int> digit;

int solve(int id, int sum1, int sum2, int y){
    if(id < 0){
        if(sum1 - sum2 <= 0)
            return 0;
        int d = sum1 - sum2;
        if(d % 3 == 0 || d % 5 == 0 || d % 7 == 0)
            return 1;
        return 0;
    }
    auto &ans = dp[id][sum1][sum2][y];
    if(ans != -1)
        return ans;
    ans=0;
    int k = y ? digit[id] : 9;
    for(int i = 0; i <= k; ++i){
        int ny = (digit[id] == i) ? y : 0;
        int nsum1 = sum1;
        int nsum2 = sum2;
        if(id&1)
            nsum1 += i;
        else
            nsum2 += i;
        ans += solve(id - 1, nsum1, nsum2, ny);
    }
    return ans;
}

int calc(int x){
    memset(dp,-1,sizeof dp);
    digit.clear();
    digit = dig(x);
    return solve(digit.size()-1, 0, 0, 1);
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<calc(b) - calc(a - 1)<<"\n";
    }
    return 0;
}
