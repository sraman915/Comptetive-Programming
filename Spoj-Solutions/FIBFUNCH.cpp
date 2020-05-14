/*
FIBFUNCH - Fun with Fibonacci Series (Challenge)
SOLUTION BY RAMAN SHARMA
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod;
ll ans[2][2];
void powfib(ll n){
	ll z[2][2],c[2][2];
	ans[0][0]=1LL;
	ans[1][1]=1LL;
	ans[0][1]=0;
	ans[1][0]=0;
	z[0][0]=1LL;
	z[0][1]=1LL;
	z[1][0]=1LL;
	z[1][1]=0;
	while(n){
		if(n&1){
	c[0][0]=(((ans[0][0]*z[0][0])%mod)+(ans[0][1]*z[1][0])%mod);
	c[0][1]=(((ans[0][0]*z[0][1])%mod)+(ans[0][1]*z[1][1])%mod);
	c[1][0]=(((ans[1][0]*z[0][0])%mod)+(ans[1][1]*z[1][0])%mod);
	c[1][1]=(((ans[1][0]*z[0][1])%mod)+(ans[1][1]*z[1][1])%mod);
	ans[0][0]=c[0][0];
	ans[0][1]=c[0][1];
	ans[1][0]=c[1][0];
	ans[1][1]=c[1][1];
		}

	c[0][0]=(((z[0][0]*z[0][0])%mod)+(z[0][1]*z[1][0])%mod);
	c[0][1]=(((z[0][0]*z[0][1])%mod)+(z[0][1]*z[1][1])%mod);
	c[1][0]=(((z[1][0]*z[0][0])%mod)+(z[1][1]*z[1][0])%mod);
	c[1][1]=(((z[1][0]*z[0][1])%mod)+(z[1][1]*z[1][1])%mod);
	z[0][0]=c[0][0];
	z[0][1]=c[0][1];
	z[1][0]=c[1][0];
	z[1][1]=c[1][1];
		n>>=1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n,m,a,b,x=0;
		cin>>a>>b>>n>>m;
        a=a%m;
		b=b%m;
		if(n==1){
            cout<<a%m<<"\n";
            continue;
		}
		if(n==2){
            cout<<(a+b)%m<<"\n";
            continue;
		}
		mod=m;
        powfib(n);
        x=(((ans[0][0]*b)%m)+((ans[0][1]*a)%m))%m;
		x=(x-b+m)%m;
		cout<<x<<"\n";
	}
	return 0;
}
