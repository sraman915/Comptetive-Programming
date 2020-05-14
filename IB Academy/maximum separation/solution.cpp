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



int solve(vector<int> &A){
int n=A.size();
map<int,vector<int> > mp;
for(int i=0; i<A.size(); ++i)
mp[A[i]].push_back(i);
int ans=0;
for(auto &it:mp){
vector<int> &v=it.s;
ans=max(ans,v.back()-v[0]);
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
assert(n>=1&&n<=200000);
vector<int> a(n);
for(int i=0; i<n; ++i)cin>>a[i];
int ans=solve(a);
cout<<ans<<"\n";
}
return 0;}
