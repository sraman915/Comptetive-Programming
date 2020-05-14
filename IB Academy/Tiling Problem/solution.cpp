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

const int MOD = 1000000007;

struct matrix{
int a[2][2];
matrix(){
memset(a,0,sizeof a);
}
matrix operator * (matrix b){
    matrix c = matrix();
    for (int i=0; i<2; ++i)
        for (int k=0; k<2; ++k)
            for (int j=0; j<2; ++j)
                c.a[i][j]=(c.a[i][j]+ (1LL*a[i][k]*b.a[k][j])%MOD)%MOD;
    return c;
}
};

matrix unit;


matrix modpow(matrix m,int n){
  if (n==0)
    return unit;
  matrix half =modpow(m,n>>1);
  matrix out=half*half;
  if(n&1)
    out=out*m;
  return out;
}


int Tiling(int n){
    if(n<=2)
        return n;
    matrix m=matrix();
    m.a[0][0]=m.a[0][1]=m.a[1][0]=1;
    unit=matrix();
    unit.a[0][0]=unit.a[1][1]=1;
    matrix p=modpow(m,n-1);
    return (p.a[0][0]+p.a[0][1])%MOD;
}

int tc=0;
const int mx=1000005;
long long dp[mx];

void pre(){
    if(tc)
        return;
    tc=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<mx; ++i)
        dp[i]=(dp[i-1]+dp[i-2])%mod;
}

int solve(int A){
    return Tiling(A);
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=1000000000);
    cout<<solve(n)<<"\n";
}
return 0;}
