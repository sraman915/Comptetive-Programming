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

int maxpointsonsameline(vector<int> &x,vector<int> &y){
int n=x.size();
if(n<2)return n;
int ans=0;
int curmax=0,overlap=0,vertical=0;
map<pair<int,int>,int> mp;
for(int i=0;i<n; ++i){
curmax=0,overlap=0,vertical=0;
for(int j=i+1; j<n; ++j){
if(x[i]==x[j]&&y[i]==y[j])++overlap;
else if(x[i]==x[j])++vertical;
else{
int xdiff=x[j]-x[i];
int ydiff=y[j]-y[i];
int z=__gcd(xdiff,ydiff);
xdiff/=z;
ydiff/=z;
mp[{xdiff,ydiff}]++;
curmax=max(curmax,mp[{xdiff,ydiff}]);
}
curmax=max(curmax,vertical);
}
mp.clear();
ans=max(ans,curmax+overlap+1);
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
vector<int> x(n),y(n);
for(int i=0; i<n; ++i)cin>>x[i];
cin>>n;
for(int i=0; i<n; ++i)cin>>y[i];
cout<<maxpointsonsameline(x,y)<<"\n";
}
return 0;}
