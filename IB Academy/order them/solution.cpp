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
stack<int> s;
int i=0,k=0;
while(i<n){
while(s.size()&&s.top()==k+1){
++k;
s.pop();
}
if(a[i]!=k+1)s.push(a[i]);
else ++k;
++i;
}
while(s.size()&&s.top()==k+1){
++k;
s.pop();
}
if(k==n)return 1;
return 0;
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
vector<int> a(n);
for(int i=0; i<n; ++i)cin>>a[i];
cout<<doit(a)<<"\n";
}
return 0;}

