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


int solve(vector<int> &a,int k){
int n=a.size();
int mx=0;
pq<int,vector<int>,greater<int> > q;
  for(auto &it:a)
      q.push(it);
while(k>0){
    int x=q.top();
    q.pop();
    if(x==0){
       k=0;
       break;
    }
    else if(x<0){
-      --k;
        q.push(-x);
    }
    else{
    if(k%2)
      q.push(-x);
    else
      q.push(x);
    k=0;
    break;
   }
}

while(!q.empty()){
   mx+=q.top();
   q.pop();
   }

return mx;
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
assert(n>=1&&n<=500000);
for(int i=0; i<n; ++i){
cin>>a[i];
assert(a[i]>=-100&&a[i]<=100);
}
cin>>k;
assert(k>=1&& k<=5000000);
int ans=solve(a,k);
cout<<ans<<"\n";
}
return 0;}
