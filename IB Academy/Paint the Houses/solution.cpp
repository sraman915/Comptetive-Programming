#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
//#define mod (long long)1000000007
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

long long mod = 1000000007;

struct matrix{
    long long a[32][32];
    matrix(){
        memset(a,0,sizeof a);
    }
    matrix operator * (matrix b){
        matrix c = matrix();
        for (int i=0; i<32; ++i)
            for (int k=0; k<32; ++k)
                for (int j=0; j<32; ++j)
                    c.a[i][j]=(c.a[i][j]+ (1LL*a[i][k]*b.a[k][j])%mod)%mod;
        return c;
    }
};

matrix unit;


matrix modpow(matrix m,long long n){
    if(n==0)
        return unit;
    matrix half=modpow(m,n>>1);
    matrix out=half*half;
    if(n&1)
        out=out*m;
  return out;
}

long long modexp(long long x, long long n){
    long long r=1LL;
    while(n){
        if(n&1)
            r=(1LL*r*x)%mod;
        x=(1LL*x*x)%mod;
        n>>=1;
    }
    return r;
}

int solveit(int n,int k,int l,int r){
    matrix m=matrix();
    unit=matrix();
    for(int i=0; i<32; ++i)
        unit.a[i][i]=1;
    for(int i=0; i<32; ++i)
        for(int j=0; j<32; ++j)
            if((i^j)<=k)
                m.a[i][j]=1;
    matrix p=modpow(m,(long long)(r-l));
    long long remaining=modexp(32LL,(long long)(n-(r+1-l)));
    long long ans=0;
    for(int i=0; i<32; ++i)
        for(int j=0;j<32; ++j){
            ans+=p.a[i][j];
            while(ans>=mod)
                ans-=mod;
    }
    ans=(1LL*ans*remaining)%mod;
    return (int)(ans);
}

int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k,l,r;
        cin>>n>>k>>l>>r;
        assert(n>=1&&n<=1000000000);
        assert(k>=0&&k<=31);
        assert(l<=r);
        assert(l>=1&&l<=n);
        assert(r>=1&&r<=n);
        cout<<solveit(n,k,l,r)<<"\n";
    }
    return 0;
}
