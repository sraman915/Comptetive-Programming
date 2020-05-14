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
int a[mxn],b[mxn],c[mxn],d[mxn],e[mxn];

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
int x;
assert(n>=2&&n<=100000);
for(int i=0; i<n; ++i)cin>>a[i];
for(int i=0; i<n; ++i){
    if(i==0)cin>>x;
    cin>>b[i];
}
for(int i=0; i<n; ++i){
    if(i==0)cin>>x;
    cin>>c[i];
}
for(int i=0; i<n; ++i){
    if(i==0)cin>>x;
    cin>>d[i];
}
for(int i=0; i<n; ++i){
assert(a[i]>=-1000000&&a[i]<=1000000);
assert(b[i]>=-1000000&&b[i]<=1000000);
assert(c[i]>=-1000000&&c[i]<=1000000);
assert(d[i]>=-1000000&&d[i]<=1000000);
}
int mx=0;
for(int p=0; p<32; ++p){
for(int i=0; i<n; ++i)e[i]=0;
int mxx=INT_MIN,mn=INT_MAX;
for(int i=0; i<n; ++i){
for(int k=0; k<5; ++k){
int temp;
if(k==0)     temp=a[i];
else if(k==1)temp=b[i];
else if(k==2)temp=c[i];
else if(k==3)temp=d[i];
else         temp=i;

if(p&(1<<k))e[i]+=temp;
else        e[i]-=temp;
}
mxx=max(mxx,e[i]);
mn=min(mn,e[i]);
}
mx=max(mx,mxx-mn);
}
assert(mx>=1);
cout<<mx<<"\n";
}
return 0;}
