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

int ab,bc,ac,abc,a,b,c,k;

bool check(int n){
    int x=1LL*(n/a+n/b+n/c);
    x-=(1LL*(n/ab+n/bc+n/ac));
    x+=(1LL*n/abc);
    return x>=k;
}

int lcm(int x,int y){
    return (1LL*x*y)/__gcd(x,y);
}


int solveit(int A,int B,int C,int D){
    a=A;
    b=B;
    c=C;
    k=D;
    ab=lcm(a,b);
    bc=lcm(b,c);
    ac=lcm(a,c);
    abc=lcm(a,bc);
    int l=1LL,r=1e18,m;
    int ans;
    while(l<=r){
        m=(l+r)>>1LL;
        if(check(m)){
            ans=m;
            r=m-1;
        }
        else
            l=m+1;
    }
    assert(ans>=1&&ans<=INT_MAX);
    return ans;
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int a,b,c,k;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>k;
    assert(a>=1&&a<=10000);
    assert(b>=1&&b<=10000);
    assert(c>=1&&c<=10000);
    assert(k>=1&&k<=10000);
    int ans=solveit(a,b,c,k);
    cout<<ans<<"\n";
}
return 0;}
