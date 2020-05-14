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

int dp[2005];//C(n+n,n)/n+1
int f[mxn],fi[mxn];

int modexp(int a, int n, int m = mod){
    int r = 1LL;
    while(n){
        if(n & 1)
            r = (1LL * r * a) % m;
        a = (1LL * a * a) % m;
        n >>= 1LL;
    }
    return r;
}

int inv(int a){
    return modexp(a, mod - 2);
}



void comb(){
    f[0] = f[1] = fi[0] = fi[1] = 1LL;
    for(int i = 2LL; i < mxn; ++i)
        f[i] = (1LL * f[i-1] * i) % mod;
    int temp = inv(f[mxn-1]);
    for(int i = mxn-1; i > 1; --i){
        fi[i] = temp;
        temp = (1LL * temp * i) % mod;
    }
}

int ncr(int n, int r){
    if(r > n || r < 0)
        return 0;
    if(r == 0 || r == n)
        return 1;
    if(r == 1 || r == n - 1)
        return n;
    return (((1LL * f[n] * fi[r]) % mod) * fi[n - r]) % mod;
}


void pre(){
    dp[0] = dp[1] = 1LL;
    for(int i = 2; i < 2001;++i)
        for(int j = 0; j < i; ++j)
            dp[i] = (dp[i] + 1LL * dp[j] * dp[i - 1 - j]) % mod;
}

int catalan(int n){
    return (1LL * ncr(n + n, n) * inv(n + 1));
    return dp[n];
}


int32_t main(){
sp;
    comb();
    pre();


return 0;}

