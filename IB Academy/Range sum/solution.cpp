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
                c.a[i][j]=(c.a[i][j]+ 1LL*a[i][k]*b.a[k][j])%mod;
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

int fibonacci(int n){
if(n<=1)return n;
if(n==2)return 1;
matrix m=matrix();
m.a[0][0]=m.a[0][1]=m.a[1][0]=1LL;
matrix p=modpow(m,n-1);
return p.a[0][0];
}

int solve(int A,int B){
    unit=matrix();
    for(int i=0; i<2; ++i)
        unit.a[i][i]=1LL;
    int sum1=fibonacci(B+2);
    int sum2=fibonacci(A+1);
    int ans=(sum1-sum2)%mod;
    ans=(ans+mod)%mod;
return ans;
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
unit=matrix();
    for(int i=0; i<2; ++i)
        unit.a[i][i]=1LL;
while(t--){
int a,b;
cin>>a>>b;
assert(a<=b);
assert(b<=1000000000);
cout<<solve(a,b)<<"\n";
}
return 0;}
