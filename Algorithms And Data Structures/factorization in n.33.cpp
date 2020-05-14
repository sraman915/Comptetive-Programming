#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define priority_queue pq
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 5000005

vector<int> v(mxn);
vector<int> b;

void sieve(){
    for(int i = 4; i < mxn; i += 2)
        v[i] = 1;
    for(int i = 3; i * i <= mxn; i += 2){
        if(v[i] == 0){
            for(int j = i * i; j <mxn; j += i+i)
                v[j] = 1;
        }
    }
    b.push_back(2LL);
    for(int i = 3; i < mxn; i += 2){
        if(v[i] == 0)
            b.push_back(i);
    }
}

int mulmod(int a, int b, int m){
    int r = 0;
    a = a % m;
    while(b){
        if(b & 1)
            r = (r + a) % m;
        a = (a << 1LL) % m;
        b = b >> 1;
    }
    return r;
}

int modexp(int x, int n, int m){
    int r = 1LL;
    while(n){
        if(n & 1)
            r = mulmod(r, x, m);
        x = mulmod(x, x, m);
        n = n>>1LL;
    }
    return r;
}

bool millerrabin(int d, int n){
    int a = 1 + rand() % (n-1);
    int x = modexp(a, d, n);
    if(x == 1 || x == n-1)
        return true;
    while(d != n-1 && x != n-1){
        x = mulmod(x, x, n);
        d <<= 1LL;
    }
    if(x != n-1)
        return false;
    return true;
}

bool isprime(int n){
    if(n == 2 || n == 3)
        return true;
    if(n <= 1|| (n & 1) == 0)
        return false;
    int d = n - 1;
    while(d % 2 == 0)
        d >>= 1;
    for(int i = 0; i < 4; ++i){
        if(!millerrabin(d,n))
            return false;
    }
    return true;
}


bool sqrprime(int n){
    int p = sqrt(n);
    if(isprime(p) && (1LL * p * p) == n)
        return true;
    return false;
}

int32_t main(){
sp;
    sieve();
    int l = b.size();
    int n;
    int t;
    cin>>n;
    int ans = 1LL;
    for(int i = 0; i < l; ++i){
        if(1LL * b[i] * b[i] * b[i] > n)
            break;
        int c = 1;
        while(n % b[i] == 0){
            ++c;
            n /= b[i];
        }
        ans *= c;
    }
    if(isprime(n))
        ans *= 2;
    else if(sqrprime(n))
        ans *= 3;
    else if(n > 1)
        ans *= 4;
    cout<<ans<<"\n";
    return 0;
}
