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

int subarraySum(vector<int>& A, int B) {
    unordered_map<long long,int> mp;
    mp[0]=1;
    long long sum=0;
    int ans=0;
    for(auto &it:A){
        sum+=it;
        ans+=mp[sum-B];
        ++mp[sum];
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
    int n;
    cin>>n;
    assert(n>=1&&n<=50000);
    vector<int> A(n);
    for(int i=0; i<n; ++i){
        cin>>A[i];
        assert(A[i]>=-1000&&A[i]<=1000);
    }
    int B;
    cin>>B;
    assert(B>=-10000000&&B<=10000000);
    int ans=subarraySum(A,B);
    cout<<ans<<"\n";
}
return 0;}
