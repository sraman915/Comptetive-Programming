/*
FLIB - Flibonakki
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define mod (ll)1000000007
#define f first
#define s second
#define inf (ll)1e15
#define pi pair<int,int>
#define pb push_back
#define mxn 100010

ll ans[2][2];
void powfib(ll n){
ans[1][1]=ans[0][0]=1LL;
ans[0][1]=ans[1][0]=0LL;
ll c[2][2],z[2][2];
z[0][0]=z[1][0]=z[0][1]=1LL;
z[1][1]=0LL;
while(n){
    if(n&1)	{
            c[0][0]=((ans[0][0]*z[0][0])%mod+(ans[0][1]*z[1][0])%mod)%mod;
			c[0][1]=((ans[0][0]*z[0][1])%mod+(ans[0][1]*z[1][1])%mod)%mod;
			c[1][0]=((ans[1][0]*z[0][0])%mod+(ans[1][1]*z[1][0])%mod)%mod;
			c[1][1]=((ans[1][0]*z[0][1])%mod+(ans[1][1]*z[1][1])%mod)%mod;
			ans[0][0]=c[0][0];
			ans[0][1]=c[0][1];
			ans[1][0]=c[1][0];
			ans[1][1]=c[1][1];
		}
		c[0][0]=((z[0][0]*z[0][0])%mod+(z[0][1]*z[1][0])%mod)%mod;
		c[0][1]=((z[0][0]*z[0][1])%mod+(z[0][1]*z[1][1])%mod)%mod;
		c[1][0]=((z[1][0]*z[0][0])%mod+(z[1][1]*z[1][0])%mod)%mod;
		c[1][1]=((z[1][0]*z[0][1])%mod+(z[1][1]*z[1][1])%mod)%mod;
		z[0][0]=c[0][0];
		z[0][1]=c[0][1];
		z[1][0]=c[1][0];
		z[1][1]=c[1][1];
		n>>=1LL;
}
}


ll fibo(ll n){
if(n==0)
return 0LL;
if(n<3)
    return 1LL;
if(n==3)
    return 2LL;
powfib(n-1);
return ans[0][0];

}

int main() {
 sp;
int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    ll temp=fibo(2LL*n);
    ll temp1=fibo(2LL*n+1LL);
    cout<<(temp*temp1)%mod<<"\n";
}
return 0;}
