/*
EKO - Eko
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 1000005

ll a[mxn],n,m;
inline bool check(ll y){
ll x=0;
for(int i=n; i>0; --i){
    if(a[i]<=y) break;
    x+=1LL*(a[i]-y);
}
return (x>=m);
}

int main(){
sp;
cin>>n>>m;
for(int i=1; i<=n; ++i)cin>>a[i];
sort(a+1,a+1+n);
ll l=1LL,r=a[n];
ll ans,mid;
while(l<=r){
    mid=(l+r)>>1;
    if(check(mid)){
        ans=mid;
        l=mid+1;
    }
    else r=mid-1;
}
cout<<ans;
return 0;}
