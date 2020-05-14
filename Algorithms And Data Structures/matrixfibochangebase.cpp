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

int ans[2][2];

void powfib(int n){
	int temp = n, z[2][2], c[2][2];
	ans[0][0] = 1;
	ans[0][1] = 0;
	ans[1][0] = 0;
	ans[1][1] = 1;

	z[0][0] = 1;
	z[0][1] = 1;
	z[1][0] = 1;
	z[1][1] = 0;
	while(temp > 0){
		if(temp & 1){
			c[0][0] = ((ans[0][0] * z[0][0]) % mod + (ans[0][1] * z[1][0]) % mod) % mod;
			c[0][1] = ((ans[0][0] * z[0][1]) % mod + (ans[0][1] * z[1][1]) % mod) % mod;
			c[1][0] = ((ans[1][0] * z[0][0]) % mod + (ans[1][1] * z[1][0]) % mod) % mod;
			c[1][1] = ((ans[1][0] * z[0][1]) % mod + (ans[1][1] * z[1][1]) % mod) % mod;

			ans[0][0] = c[0][0];
			ans[0][1] = c[0][1];
			ans[1][0] = c[1][0];
			ans[1][1] = c[1][1];
		}
		c[0][0] = ((z[0][0] * z[0][0]) % mod + (z[0][1] * z[1][0]) % mod) % mod;
		c[0][1] = ((z[0][0] * z[0][1]) % mod + (z[0][1] * z[1][1]) % mod) % mod;
		c[1][0] = ((z[1][0] * z[0][0]) % mod + (z[1][1] * z[1][0]) % mod) % mod;
		c[1][1] = ((z[1][0] * z[0][1]) % mod + (z[1][1] * z[1][1]) % mod) % mod;

		z[0][0] = c[0][0];
		z[0][1] = c[0][1];
		z[1][0] = c[1][0];
		z[1][1] = c[1][1];
		temp >>= 1;
	}
}

int fibo(int n, int a = 0, int b = 1){
    if(n == 0)
        return a;
    if(n == 1)
        return b;
    if(n == 2)
        return a + b;
    powfib(n-1);
    return ((b * ans[0][0] % mod) + (a * ans[0][1] % mod)) % mod;
}

int32_t main(){
sp;
	int t, n, a, b;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		cout<<fibo(n, a, b)<<"\n";
    }
	return 0;}
