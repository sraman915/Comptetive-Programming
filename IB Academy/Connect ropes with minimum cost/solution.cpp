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

int doit(vector<int> &a){
int n=a.size();

priority_queue<int,vector<int>,greater<int> > q;

for(auto &it:a){
   q.push(it);
   }
int ans=0;

while(q.size()>1){
   int x=q.top();
   q.pop();
   int y=q.top();
   q.pop();
   ans+=(x+y);
   q.push(x+y);
}
 assert(ans>=0&&ans<=INT_MAX);

return ans;
}

int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
assert(n>=1&&n<=100000);
vector<int> a(n);
for(int i=0;i<n; ++i){
cin>>a[i];
assert(a[i]>=1&&a[i]<=1000);
}
int ans=doit(a);
cout<<ans;
cout<<"\n";
}
return 0;}

