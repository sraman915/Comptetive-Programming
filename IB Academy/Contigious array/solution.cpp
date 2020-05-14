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


int findMaxLength(vector<int>& A) {
    int n=A.size();
    if(n==0)
        return 0;
    unordered_map<int,int> mp;
    int sum=0,ans=0;
    mp[0]=-1;
    for(int i=0; i<A.size(); ++i){
        if(A[i]==0)
            --sum;
        else
            ++sum;
        if(mp.find(sum)==mp.end())
            mp[sum]=i;
        else
            ans=max(ans,i-mp[sum]);
    }
    assert(ans>=0&&ans<=n);
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
    assert(n>=1&&n<=100000);
    vector<int> A(n);
    for(int i=0; i<n; ++i){
        cin>>A[i];
        assert(A[i]>=0&&A[i]<=1);
    }
    int ans=findMaxLength(A);
    cout<<ans<<"\n";
}
return 0;}
