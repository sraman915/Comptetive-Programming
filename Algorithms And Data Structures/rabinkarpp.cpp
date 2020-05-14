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
#define mxn 200005

string pat,text;

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

ll inv(ll x){
return modexp(x,mod-2);
}

void ans(){
ll m=pat.size();
ll n=text.size();
ll phash=0;
for(int i=0; pat[i]; ++i)
phash=(phash+(pat[i]-'a'+1)*modexp(m,1LL*i))%mod;
ll m1=inv(m);
ll thash=0;
for(int i=0; i<m; ++i)
thash=(thash+(text[i]-'a'+1)*modexp(m,1LL*i))%mod;
int z=1;
if(thash==phash){
    for(int i=0; i<m; ++i)
    if(pat[i]!=text[i])
        break;
    else ++z;
}
if(z==m)cout<<"PATTERN FOUND AT\n"<<0<<"\n";
z=0;
for(ll i=m; i<n; ++i){
        ll prev=text[i-m]-'a'+1;
    thash=(((thash-prev+mod)%mod*m1)%mod+(text[i]-'a'+1)*modexp(m,1LL*m-1))%mod;
    if(thash==phash){
        for(int j=0; j<m; ++j)
        if(text[i-m+1+j]==pat[j])
            ++z;
        else break;
    }
    if(z==m)cout<<i-m+1<<"\n";
    z=0;
}
}

int main(){
sp;

cin>>pat>>text;
ans();
return 0;}
