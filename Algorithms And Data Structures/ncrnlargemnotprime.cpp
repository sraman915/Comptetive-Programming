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

int fact[650],a[700],b[701];

int mul(int x,int n,int m){
    int r=0LL;
    if(n>x)
        swap(x,n);
    while(n){
        if(n&1){
            r=(r+x);
        if(r>=m)
            r-=m;
        }
        x=(x<<1LL);
        if(x>=m)
            x-=m;
        n>>=1;
    }
    return r;
}


void solve(int n,int k,int m){
    if(n==0){
        a[0]=1;
    return ;
    }
    solve(n/2,k,m);
    for(int i=0; i<=k; ++i){
        int p=0;
        for(int j=0; j<=i; ++j){
            p=(p+mul(a[j],a[i-j],m));
        if(p>=m)
            p-=m;
        }
        b[i]=p;
    }
    for(int i=0; i<=k; ++i)
        a[i]=b[i];
    if(n&1){
        for(int i=k; i>0; --i){
            a[i]=(a[i]+a[i-1]);
        if(a[i]>=m)
            a[i]-=m;
    }
    }
}

void pre(int m){
    fact[0]=1LL%m;
    for(int i=1LL; i<650; ++i)
        fact[i]=mul(fact[i-1],i,m);
}



int32_t main(){
sp;

    int n,k,m;
    cin>>n>>k>>m;
    pre(m);
    solve(n+1,k+1,m);
    int ans=0;
    for(int i=1; i<=k; ++i){
        ans=(ans+mul(fact[i],a[i+1],m));
    if(ans>=m)
        ans-=m;
    }
    cout<<ans;
    return 0;
}
