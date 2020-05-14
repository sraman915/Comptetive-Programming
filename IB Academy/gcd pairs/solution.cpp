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

int a[mxn],b[mxn],c[mxn],n,k;


int nc2(int n){
return (((1LL*n*(n-1))/2)%mod);
}

int add(int x,int y){
    x%=mod;
    y%=mod;
int z=(x+y);
while(z>=mod)z-=mod;
return z;
}

int sub(int x,int y){
x%=mod;
y%=mod;
int z=x-y;
while(z<0)z+=mod;
while(z>=mod)z-=mod;
return z;
}

int solve(){
int mx=0,ans=0;
cin>>n;
assert(n>=1&&n<=100000);
for(int i=1; i<=n; ++i){
    int x;
    cin>>x;
    assert(x>=1&&x<=100000);
    ++a[x];
    mx=max(mx,x);
}
cin>>k;
for(int i=mx; i>k; --i){
    int z=a[i];
    int y=0;
    int j=i+i;
    while(j<=mx){
        z+=a[j];
        y+=b[j];
        j+=i;
    }
    b[i]=sub(nc2(z),y);
    cout<<i<<" "<<b[i]<<" "<<y<<" "<<z<<" "<<ans<<"\n";;
    ans=add(ans,b[i]);
}
for(int i=1; i<=mx; ++i){
    a[i]=0;
    b[i]=0;
}
assert(ans>=0&&ans<mod);
cout<<ans<<"\n";
}

int32_t main(){
sp;
/*
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
*/
int t;
cin>>t;
while(t--){
    solve();
}
return 0;}
