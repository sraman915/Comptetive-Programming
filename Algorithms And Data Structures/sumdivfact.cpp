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
#define pi pair<ll,ll>
#define pii pair<int,pi>
#define pb push_back
#define mxn 1000005
vector<ll> a(mxn),p(mxn),ans(mxn);

void pre(){
a[1]=a[0]=1;
for(ll i=2; i<mxn; i+=2)a[i]=2;
for(ll i=3; i*i<=mxn; i+=2)
    if(!a[i])for(ll j=i*i; j<mxn; j+=i+i)
    if(!a[j])a[j]=i;
for(int i=3; i<mxn; i+=2)if(!a[i])a[i]=i;
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

vector<pi> fact(ll n){
vector<pi> x;
while(n>1){
    ll z=0;
    ll y=a[n];
    while(n%y==0){
        ++z;
        n/=y;
    }
    x.pb({y,z});
}
return x;
}

ll leg(ll n,ll x){
ll y=0;
while(n){
    n/=x;
    y+=n;
}
return y;
}

ll inv(ll x){
return modexp(x,mod-2);
}

ll pre1(){
pre();
ans[1]=1;
for(ll i=2; i<mxn; ++i){
        ans[i]=1LL;
vector<pi> y=fact(i);
for(int j=0; j<y.size(); ++j){
    ll p1=y[j].f;
    ll p2=y[j].s;
    if(p[p1]==0){
        ll temp=(modexp(p1,p2+1)-1+mod)%mod;
        ll temp1=inv(p1-1);
        temp=(temp*temp1)%mod;
        p[p1]=p2;
        ans[i]=(ans[i]*temp)%mod;
    }
    else{
        ll o=p[p1];
        ll n=p[p1]+p2;
        p[p1]=n;
        ll temp=(modexp(p1,n+1)-1+mod)%mod;
        ll temp1=(modexp(p1,o+1)-1+mod)%mod;
        temp1=inv(temp1);
        temp=(temp*temp1)%mod;
        ans[i]=(ans[i]*temp)%mod;}
}
ans[i]=(ans[i]*ans[i-1])%mod;
}
}


int main(){
sp;
pre1();
int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    cout<<ans[n]<<"\n";
}
return 0;}
