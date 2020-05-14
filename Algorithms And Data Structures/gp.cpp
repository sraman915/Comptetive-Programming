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


int modexp(int x,int n,int m=mod){
    int r=1LL;
    x%=mod;
    while(n){
        if(n&1)
            r=(r*x)%m;
        x=(1LL*x*x)%m;
        n>>=1LL;
    }
    return r;
}

int inv(int x){
    return modexp(x,mod-2);
}

int sumofgp(int x,int r,int n){
    if(r<0)
        r+=mod;
    int sum=(1LL*x*(modexp(r,n)-1LL+mod)%mod)%mod;
    sum%=mod;
    sum=(1LL*sum*inv(r-1))%mod;
    return sum;
}

int nthtermofgp(int x,int r,int n){
    if(r<0)
        r+=mod;
    int an=(1LL*x*modexp(r,n-1))%mod;
    return an;
}


int32_t main(){
sp;

    cout<<sumofgp(1,3,3);

    return 0;
}
