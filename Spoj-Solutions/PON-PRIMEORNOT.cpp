/*
PON-PRIME OR NOT
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
for(int i=0; i<6; ++i){
    if(!millerrabin(d,n))
        return false;
}
return true;
}
int main(){
int t;
scanf("%d",&t);
while(t--){
    ll n;
    scanf("%llu",&n);
    if(isprime(n))
        printf("YES\n");
    else printf("NO\n");
}
return 0;}
