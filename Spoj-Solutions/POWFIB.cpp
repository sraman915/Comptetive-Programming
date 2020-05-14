/*
POWFIB-FIBO AND NON FIBO
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll modexp(ll x,ll n,ll m){
ll r=1;
while(n){
    if(n&1)
        r=(r*x)%m;
    x=(x*x)%m;
    n=n>>1;
}
return r;
}
ll nonfib(ll n){
ll a=1,b=2,c=3;
while(n>0){
    a=b;
    b=c;
    c=a+b;
    n-=(c-b-1);
}
n+=(c-b-1);
return n+b;
}
ll ans[2][2];
void powfib(ll n){
	ll temp=n,z[2][2],c[2][2];
	ans[0][0]=1;
	ans[0][1]=0;
	ans[1][0]=0;
	ans[1][1]=1;
	z[0][0]=1;
	z[0][1]=1;
	z[1][0]=1;
	z[1][1]=0;
	while(temp>0){
		if(temp%2==1)
		{
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
		temp=temp/2;
	}
}
int main(){
int t;
scanf("%d",&t);
while(t--){
    ll n;
    scanf("%lld",&n);
    ll a,b;
    a=nonfib(n);
    if(n==1)
        b=1;
    else{
        powfib(n-1);
        b=ans[0][0];
    }
    printf("%lld\n",modexp(a,b,mod));
}
return 0;}
