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

vector<int> doit(vector<int> &a,int k){
int n=a.size();
vector<int> ans;
deque<int> q;
for(int i=0; i<k; ++i)
if(a[i]<0)q.push_back(i);
for(int i=k; i<n; ++i){
if(q.empty())ans.push_back(0);
else ans.push_back(a[q.front()]);
while(!q.empty()&&q.front()<i-k+1)q.pop_front();
if(a[i]<0)q.push_back(i);
}
if(!q.empty())ans.push_back(a[q.front()]);
else ans.push_back(0);
return ans;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,k;
cin>>n;
vector<int> a(n);
for(int i=0;i<n; ++i)cin>>a[i];
cin>>k;
assert(n>=1&&n<=200000);
assert(k>=1&&k<=n);
vector<int> ans=doit(a,k);
for(auto &it:ans)cout<<it<<" ";
cout<<"\n";
}
return 0;}
