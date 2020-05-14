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

int SubarraySumK(vector<int> &A,int B) {
    unordered_map<int, int> um;
    int n=A.size();
    int sum = 0, maxLen = -1;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum == B)
            maxLen = i + 1;
        if (um.find(sum) == um.end())
            um[sum] = i;
        if (um.find(sum - B) != um.end()) {
            if (maxLen < (i - um[sum - B]))
                maxLen = i - um[sum - B];
        }
    }
    return maxLen;
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
assert(a[i]>=-1000000&&a[i]<=1000000);
}
int k;
cin>>k;
assert(k>=-1000000000&&k<=1000000000);
int ans=SubarraySumK(a,k);
cout<<ans<<"\n";
}
return 0;}
