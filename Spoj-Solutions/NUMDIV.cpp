/*
NUMDIV - Number of divisors
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<int> v(5000001);
vector<ll> b;
void sieve(){
for(int i=2; i*i<=5000001; ++i){
    if(!v[i]){
        for(int j=i*i; j<5000001; j+=i)
            v[j]=1;
    }
}
b.push_back(2);
for(ll i=3; i<5000001; i+=2){
    if(!v[i])
        b.push_back(i);
}
}
ll mulmod(ll a,ll b,ll m){
ll r=0;
a=a%m;
while(b){
    if(b&1)
        r=(r+a)%m;
    a=(a*2)%m;
    b=b>>1;
}
return r;
}
ll modexp(ll x,ll n,ll m){
ll r=1;
while(n){
    if(n&1)
        r=mulmod(r,x,m);
    x=mulmod(x,x,m);
    n=n>>1;
}
return r;
}
bool millerrabin(ll d,ll n){
    ll a=1+rand()%(n-1);
    ll x=modexp(a,d,n);
    if(x==1||x==n-1)
        return true;
    while(d!=n-1&&x!=n-1){
        x=mulmod(x,x,n);
        d*=2;
    }
    if(x!=n-1)
        return false;
return true;
}
bool isprime(ll n){
if(n==2||n==3)
    return true;
if(n<=1||(n&1)==0)
    return false;
ll d=n-1;
while(d%2==0)
    d>>=1;
for(int i=0; i<4; ++i){
    if(!millerrabin(d,n))
        return false;
}
return true;
}
bool sqrprime(ll n){
ll p=sqrt(n);
if(isprime(p)&&(p*p)==n)
    return true;
return false;
}
int main(){
    sieve();
    int l=b.size();
ll n;
int t;
cin>>t;
while(t--){
cin>>n;
ll ans=1;
for(int i=0; i<l; ++i){
if(b[i]*b[i]*b[i]>n)
    break;
ll c=1;
while(n%b[i]==0){
    ++c;
    n/=b[i];
}
ans=ans*c;
}
if(isprime(n))
    ans=ans*2;
else if(sqrprime(n))
ans=ans*3;
else if(n>1)
    ans=ans*4;
cout<<ans<<endl;
}
return 0;
}
