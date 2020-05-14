#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (int)1000000007
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
#define mxn 1005

int c[mxn][mxn], p[mxn], dp[mxn][mxn], inv2;

int modexp(int a, int n){
    int r = 1LL;
    while(n){
        if(n & 1)
            r = (1LL * r * a) % mod;
        a = (1LL * a * a) % mod;
        n >>= 1LL;
    }
    return r;
}

int inv(int a){
    return modexp(a, mod - 2);
}


void pre(){
    p[0] = 1;
    inv2 = inv(2LL);
    for(int i = 1; i < mxn; ++i){
        p[i] = (p[i-1] << 1);
        if(p[i] >= mod)
            p[i] -= mod;
    }
    for(int i = 1; i < mxn; ++i){
        c[i][0] = c[i][i] = 1;
        c[i][1] = c[i][i-1] = i;
        for(int j = 2; j < i; ++j){
            c[i][j] = c[i-1][j] + c[i-1][j-1];
            if(c[i][j] >= mod)
                c[i][j] -= mod;
        }
    }
    for(int i = 1; i < mxn; ++i){
        int x = 1LL*i;
        for(int j = 0; j < i; ++j){
            dp[i][j] = dp[i-1][j] + x;
            if(dp[i][j] >= mod)
                dp[i][j] -= mod;
            x=(1LL* x * i) % mod;
        }
    }
}


int F(int n,int k){
    if(k == 0)
        return n % mod;
    if(n == 1)
        return 1;
    if(n == 2)
        return p[k]+1;
    if(k == 1){
        n %= mod;
        int ans=(((1LL * n * (n+1)) % mod) * inv2) % mod;
        return ans%mod;
    }
    int h = (n<<10)|k;
    int res = 0;
    if(n&1)
        res = F(n-1, k) + modexp(n, k);
    else{
        int m,z;
        m = n>>1;
        res = (1LL * F(m,k) * p[k]) % mod;
        m--, ++res;
        for(int i = 0; i <= k;++i){
            z = (1LL * F(m, i) * c[k][i]) % mod;
            z = (1LL * z * p[i]) % mod;
            res += z;
            if(res >= mod)
                res -= mod;
        }
    }
    res %= mod;
    return res;
}

int sum1(int k){
    int tot = k /2;
    if(tot == 0)
        return 0;
    int start = 2;
    int en = tot * 2;
    int sum = (1LL * (start + en) * tot )/ 2;
    sum %=mod;
    if( sum == 0)
        return 0;
    return -sum + mod;
}

int32_t main(){
sp;
    pre();
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int s1 = F(n, k);
        int s2 = sum1(k);
        s1 += s2;
        while(s1 >= mod)
            s1 -= mod;
        cout<<s1<<"\n";
    }
return 0;}
