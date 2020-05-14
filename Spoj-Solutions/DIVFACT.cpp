/*
DIVFACT - DIVISORS OF FACTORIAL
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;
vector<ll> a(100010,1),v;
void sieve(){
    a[1]=a[0]=0;
    for(ll i=2; i*i<=100010; ++i){
        if(a[i]){
            for(ll j=i*i; j<100010; j+=i)
                a[j]=0;}}
    v.push_back(2);
    for(ll i=3; i<100010; i+=2){
        if(a[i])
            v.push_back(i);}
}
ll legendre(ll n,ll x){
ll aa=0;
while(n){
    n/=x;
    aa=(aa+n)%mod;;
}
return aa;
}
ll ans(ll n){
    ll r=1,temp=0;
    for(ll i=0; i<v.size(); ++i){
        if(n<v[i])
            break;
        temp=legendre(n,v[i]);
        r=(r*(temp+1))%mod;
    }
  return r;
}
int main(){
int q;
cin>>q;
sieve();
while(q--){
    ll n;
    cin>>n;
    cout<<ans(n)<<endl;
}
return 0;
}
