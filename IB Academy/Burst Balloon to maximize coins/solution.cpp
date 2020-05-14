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

int dp[105][105];
int rec(int i,int j,vector<int> &A){
        if(j-i<=1)
            return 0;
        auto &ans=dp[i][j];
        if(ans!=-1)
            return ans;
        ans=0;
        for(int k=i+1; k<=j-1; ++k)
            ans=max(ans,rec(i,k,A)+rec(k,j,A)+A[i]*A[k]*A[j]);
        return ans;
}
int maxCoins(vector<int>& A) {
    A.insert(A.begin(), 1);
    A.push_back(1);
    int n=A.size();
    for(int i=0;i<=n; ++i)
        for(int j=0; j<=n; ++j)
            dp[i][j]=-1;
    int ans=rec(0,n-1,A);
    assert(ans<=INT_MAX);
    return ans;
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
    assert(n>=1&&n<=100);
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
        assert(a[i]>=1&&a[i]<=100);
    }
    int ans=maxCoins(a);
    cout<<ans<<"\n";
}
return 0;}
