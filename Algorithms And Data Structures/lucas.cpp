#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
//#define mod (long long)1000000007
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

const int mod = 1000003;

int f[mod + 1], fi[mod + 1];

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
    for(int i = 2LL; i < mod; ++i)
        f[i] = (1LL * f[i - 1] * i) % mod;
    int temp = inv(f[mod - 1]);
    for(int i = mod - 1; i > 1; --i){
        fi[i] = temp;
        temp = (1LL * temp * i) % mod;
    }
}

int leg(int n){
    int x = 0;
    while(n){
        n /= mod;
        x += n;
    }
    return x;
}

int lucas(int n, int r){
    if(r > n)
        return 0;
    if(r == n || r == 0)
        return 1;
    if(r == 1 || r == n - 1)
        return (n % mod);
    int x1 = leg(n);
    int x2 = leg(r);
    int x3 = leg(n - r);
    if(x1 > x2 + x3)
        return 0;
    int temp = 1LL;
    while(n){
        x1 = n % mod;
        x2 = r % mod;
        if(x1 < x2)
            return 0;
        temp = (1LL * temp * f[x1]) % mod;
        int temp1 = (1LL * fi[x2] * fi[x1 - x2]) % mod;
        temp = (1LL * temp * temp1) % mod;
        n /= mod;
        r /= mod;
    }
    return temp;
}


int32_t main(){
sp;
    comb();
    int n = 10, r = 2;
    cout<<lucas(n, r);
    return 0;
}
