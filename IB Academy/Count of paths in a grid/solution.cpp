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

const int N = 3000005;
const long long MOD = 1000000007;
long long f[N],fi[N];
int tc=0;

long long modexp(long long a,long long n,long long m=mod){
    long long r=1LL;
    while(n){
        if(n&1)
            r=(r*a)%m;
        a=(a*a)%m;
        n>>=1LL;
    }
    return r;
}

long long inv(int a){
    return modexp(a,mod-2);
}

void comb(){
    if(tc)
        return;
    tc=1;
    f[0]=f[1]=fi[0]=fi[1]=1LL;
    for(long long i=2LL; i<N; ++i)
        f[i]=(1LL*f[i-1]*i)%mod;
    int temp=inv(f[N-1]);
    for(long long i=N-1; i>1; --i){
        fi[i]=temp;
        temp=(temp*i)%mod;
    }
}

long long ncr(long long n,long long r){
    if(r>n||r<0)
        return 0LL;
    if(r==0||r==n)
        return 1LL;
    if(r==1||r==n-1)
        return n;
    return (((1LL*f[n]*fi[r])%mod)*fi[n-r])%mod;
}

long long nthCatalan(int n){
    long long ans=ncr(n+n,n);
    ans=(1LL*ans*inv(n+1))%MOD;
    return ans;
}

int solve(int n){
    if(n==0)
        return 1;
    comb();
    int ans=nthCatalan(n);
    return ans;
}




int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=1000000);
    int ans=solve(n-1);
    cout<<ans<<"\n";
}
return 0;}
