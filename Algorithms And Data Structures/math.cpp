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


int mulmod(int a, int b, int m){
    int r = 0;
    a = a % m;
    b = b % m;
    if(a < b)
        swap(a, b);
    while(b){
        if(b & 1)
            r = (r + a) % m;
        a = (a * 2) % m;
        b >>= 1;
    }
    return r;
}

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


int p[mxn];

void sieve(){
    p[1] = p[0] = 1;
    for(int i = 4; i < mxn; i += 2)
        p[i] = 1;
    for(int i = 3; i * i < mxn; i += 2)
        if(p[i] == 0)
            for(int j = i * i; j < mxn; j += i + i)
                p[j] = 1;
}


int inv(int a){
    return modexp(a, mod - 2);
}

int pqinv(int p, int q){
    return (1LL * p * inv(q)) % mod;
}


bool primecheck(int x){
    if(x == 2)
        return 1;
    if(x < 2 || x % 2 == 0)
        return 0;
    for(int i = 3; i * i <= x; i += 2)
        if(x % i == 0)
            return 0;
    return 1;
}


void minprime(){
    for(int i = 2; i < mxn; i += 2)
        p[i] = 2;
    for(int i = 3; i * i < mxn; i += 2)
        if(p[i] == 0)
            for(int j = i * i; j < mxn; j += i + i)
                if(p[j] == 0)
                    p[j] = i;
    for(int i = 3; i < mxn; i += 2)
        if(p[i] == 0)
            p[i] = i;
}


int f[mxn], fi[mxn];

void pre(){
    f[0] = f[1] = fi[0] = fi[1] = 1LL;
    for(int i = 2LL; i < mxn; ++i)
        f[i] = (1LL * f[i - 1] * i) % mod;
    int temp = inv(f[mxn - 1]);
    for(int i = mxn - 1; i > 1; --i){
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

int c[2005][2005];

void comb(){
    for(int i = 1; i < 2005; ++i){
        c[i][0] = c[i][i] = 1LL;
        c[i][1] = i;
        for(int j = 2; j < i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}



int iv[mxn], kk, nn;

void ncrforfixedn(){
    iv[0] = iv[1] = 1;
    for(int i = 2; i <= kk; ++i)
        iv[i] = (1LL * iv[mod % i] * (mod - mod/i)) % mod;//inv using extended euclid based on prevoius inverses
    c[0] = 1, c[1] = nn;
    for(int i = 2; i <= kk; ++i)
        c[i] = (((1LL * c[i-1] * (nn + 1 - i)) % mod) * iv[i]) % mod;//when n is large kk is smaint
    //C(n,r)=C(n,r-1)*((n+1-r)/r)
}



int ncrwhenrissmaint(int n,int r){
    if(r > n)
        return 0;
    if(n == r || r == 0)
        return 1;
    int ans = 1;
    if(r > n - r)
        r = n - r;

    for(int i = 0; i < r; ++i){
        ans *= (n - i);
        ans /= (i + 1LL);
    }
    return ans;
}


int d,x,y;
void extendedeuclid(int a, int m) {
    if(m==0) {
        d=a;
        x=1;
        y=0;
    }
    else {
        extendedeuclid(m, a%m);
        int temp=x;
        x=y;
        y=temp-(a/m)*y;
    }
}
int modinverse(int a,int m){
extendedeuclid(a,m);
return ((x%m)+m)%m;
}

int d[b-a+10];
void segsieve(int a, int b){
    memset(d,0,sizeof d);
    for(int i = a; i < b + 1; ++i)
        d[i-a] = 2;
    if(a == 1)
        d[0] = 1;
    for(int i = 2; i * i <= b; ++i){
        for(int j = ((a - 1)/i + 1) * i; j <= b; j += i){
            if(j < i * i)
                continue;
            if(j == i * i)
                d[j - a] += 1;
            else
                d[j - a] += 2;
        }
    }
}

int phi(int n){
    int temp = n;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            while(n % i == 0)
                n /= i;
            temp = temp - temp/i;
        }
    }
    if(n>1)
        temp = temp - temp/n;
    return temp;
}

void phisieve(){
    for(int i = 1; i < mxn; ++i)
        p[i] = i;
    for(int i = 2; i < mxn; ++i)
        if(p[i] == i){
            for(int j = i; j < mxn; j += i){
                p[j] /= i;
                p[j] *= (i - 1);
            }
        }
}


int32_t main(){
return 0;
}
