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
        n = n >> 1LL;
    }
    return r;
}

bool millerrabin(int d, int n){
    int a = 1 + rand() % (n - 1);
    int x = modexp(a, d, n);
    if(x == 1 || x == n - 1)
        return true;
    while(d != n - 1 && x != n - 1){
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
    if(n <= 1 || (n & 1) == 0)
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


int32_t main(){
sp;
    int t;
    cout<<isprime(999999999999999989)<<endl;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(isprime(n))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
