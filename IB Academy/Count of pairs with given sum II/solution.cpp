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

const int MOD = 1000000007;

int solveit(vector<int> &A,int B){
    int n=A.size();
    for(int i=1; i<n; ++i)
        assert(A[i]>=A[i-1]);
    unordered_map<long long,long long> mp;
    long long ans=0;
    for(int i=0; i<n; ++i){
        int y=B-A[i];
        if(mp.find(y)!=mp.end()){
            ans+=mp[y];
            while(ans>=MOD)
                ans-=MOD;
        }
        ++mp[A[i]];
    }
    assert(ans>=0&&ans<MOD);
    return (int)(ans);
}

int32_t main(){
sp;
freopen("input2.txt","r",stdin);
freopen("output2.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=100000);
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
        assert(a[i]>=1&&a[i]<=1000000000);
    }
    int b;
    cin>>b;
    assert(b>=1&&b<=1000000000);
    int ans=solveit(a,b);
    cout<<ans<<"\n";
}
return 0;}
