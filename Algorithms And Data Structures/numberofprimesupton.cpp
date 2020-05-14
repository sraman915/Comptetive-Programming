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
#define mxn 10000005

bool prime[mxn];
int prec[mxn];
vector<int> p;

const int mx = 250;
int dp[mx * mx][mx];


void sieve(){
    prime[2] = true;
    for(int i = 3; i < mxn; i += 2)
        prime[i] = true;
    for(int i = 3; i * i < mxn; i += 2)
        if(prime[i])
            for(int j = i * i; j < mxn; j += i + i)
                prime[j] = false;
    for(int i = 2; i < mxn; ++i){
        prec[i] = prec[i - 1] + prime[i];
        if(prime[i])
            p.push_back(i);
    }
}


int rec(int N, int K) {
    if(N <= 1 || K < 0)
        return 0;
    if(N <= p[K])
        return N-1;
    if(N < mxn && p[K] * 1LL * p[K] > N)
        return N - 1 - prec[N] + prec[p[K]];
    bool ok = N < mx * mx && K < mx;
    if(ok && dp[N][K])
        return dp[N][K];

    int ret = N / p[K] - rec(N / p[K], K - 1) + rec(N, K - 1);
    if(ok)
        dp[N][K] = ret;
    return ret;
}

int primenumbersupto_N(int n){
    if(n <  mxn)
        return prec[n];
    int k = prec[(int)sqrt(n) + 1];
    return n - 1 - rec(n, k) + prec[p[k]];
}


int32_t main(){
sp;
    sieve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<primenumbersupto_N(n)<<"\n";
    }
    return 0;
}
