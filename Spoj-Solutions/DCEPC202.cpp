/*
SOLUTION BY RAMAN SHARMA
DCEPC202 - Unique Paths
https://www.spoj.com/problems/DCEPC202/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)998244353
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
#define mxn 200005
ll k;

ll ncr(ll n,ll r){
if(r>n)return 0;
if(r==n||r==0)return 1;
if(r==n-1||r==1)return n;
if(r>n-r)r=n-r;
ll ans=1LL;
for(ll i=0; i<r; ++i){
    ans=(1LL*ans*(n-i));
    ans/=(i+1);
}
return ans;
}

bool check(ll n){
ll p=ncr(n+3,4);
ll q=ncr(n/2+4,4);
ll r=ncr(n+1,2);
ll s=ncr(n-(n/2)+3,4);
ll t=ncr((n/2)+2,2);
ll u=ncr(n-(n/2)+1,2);
ll temp=p-s-r-r-1LL*t*u-q+u+u+u+t+t+t-2;
//cout<<n<<" "<<temp<<"\n";
return (temp>=k);
}


int main(){
sp;
int t;
cin>>t;
while(t--){
    cin>>k;
    if(k>=1000000000000000){
        cout<<"10000\n";
        continue;
    }
    ll ans=-1;
    ll l=4,r=10000,m;
    while(l<=r){
        m=(l+r)>>1;
        if(check(m)){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    cout<<ans<<"\n";
}
return 0;}
