/*
http://www.spoj.com/problems/ADAGCD/
ADAGCD - Ada and GCD
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
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 10000005
ll a[mxn],b[mxn],vis[mxn];

void pre(){
a[1]=a[0]=1;
for(int i=2; i<mxn; i+=2)a[i]=2LL;
for(int i=3; i*i<=mxn; i+=2)
    if(!a[i])for(int j=i*i; j<mxn; j+=i+i)
    if(!a[j])a[j]=1LL*i;
for(ll i=3; i<mxn; i+=2)
    if(!a[i])a[i]=i;
}

ll modexp(ll x,ll n){
ll r=1LL;
while(n){
    if(n&1)
        r=(r*x)%mod;
    x=(x*x)%mod;
    n>>=1;
}
return r;
}


int main(){
sp;
pre();
ll n,m,x;
cin>>n;
for(int i=0; i<n; ++i){
 cin>>m;
 map<ll,ll> mp;
 mp.clear();
 for(int j=0; j<m; ++j){
    cin>>x;
    while(x>1){
        ++mp[a[x]];
        x/=a[x];
    }
 }
 if(!i){
    for(auto it:mp)
 b[it.f]=it.s,vis[it.f]++;
 }
 else{
for(auto it:mp)
 b[it.f]=min(b[it.f],it.s),vis[it.f]++;
}}
ll ans=1LL;
for(ll i=1LL; i<mxn; ++i){
    if(b[i]==inf||a[i]!=i||vis[i]!=n)continue;
    //debug2(i,b[i]);
    ans=(ans*modexp(i,b[i]))%mod;
}
cout<<ans;
return 0;}
