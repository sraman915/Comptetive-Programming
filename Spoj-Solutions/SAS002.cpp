/*
SAS002 - Apoorv and Math problem
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
#define mxn 5000010
int a[mxn];
vector<ll> p;
int l;

void sieve(){
a[0]=a[1]=1;
for(int i=4; i<mxn; i+=2)a[i]=1;
p.pb(2LL);
for(ll i=3; i*i<=mxn; i+=2)
if(!a[i])for(int j=i*i; j<mxn; j+=i+i)a[j]=1;
for(ll i=3LL; i<mxn; i+=2LL)if(!a[i])p.pb(i);
l=p.size();
}

ll mulmod(ll x,ll n,ll m=mod){
ll r=0LL;
x%=m;
while(n){
        if(n&1)
        r=(r+x)%m;
x=(x+x)%m;
n>>=1LL;
}
return r;
}

ll modexp(ll x,ll n,ll m=mod){
ll r=1LL;
while(n){
        if(n&1)
        r=mulmod(r,x,m);
x=mulmod(x,x,m);
n>>=1LL;
}
return r;
}

bool mr(ll d,ll n){
ll a=1+rand()%(n-1);
ll x=modexp(a,d,n);
if(x==1||x==n-1)return true;
while(d!=n-1&&x!=n-1){
    x=mulmod(x,x,n);
    d<<=1LL;
}
if(x!=n-1)return false;
return true;
}

bool isprime(ll n){
if(n<2)return 0;
if(n==3||n==5||n==2)return 1;
if(n%3==0||n%5==0||n%2==0)return 0;
ll d=n-1;
while(d%2==0)
    d>>=1LL;
for(int i=0; i<4; ++i)
    if(!mr(d,n))return false;
return true;
}

bool sqrprime(ll n){
ll p=sqrt(n);
if(isprime(p)==0)return 0;
if(p*p==n)return 1;
return 0;
}

ll func(ll n){
    if(n==1)return 1LL;
ll d=1LL,y=n;
for(int i=0; i<l; ++i){
    if(p[i]*p[i]*p[i]>n) break;
    ll x=1LL;
    while(n%p[i]==0){
        ++x;
        n/=p[i];
    }
    d*=x;
}
if(n>1){
if(isprime(n))
    d<<=1LL;
else if(sqrprime(n))
    d*=3LL;
else d*=4LL;
}
ll x=1LL;
if(d&1)
     x=sqrt(y);
ll ans=mulmod(modexp(y,d>>1LL),x);
return ans;
}

int main(){
sp;
sieve();
int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    cout<<func(n)<<"\n";
}
return 0;}
