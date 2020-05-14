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

unordered_map<int, int> F;

int f(int n) {
	if(F.count(n))
        return F[n];
	int k = n/2;
	if(n % 2 == 0)
		return F[n] = (f(k) * (f(k-1) + f(k+1))) % mod;
    return F[n] = (f(k) * f(k) + f(k+1) * f(k+1)) % mod;
}

int32_t main(){
sp;
	int n;
	int t;
	cin>>t;
	F[0] = 0;
	F[1] = F[2] = 1LL;
	while(t--){
        cin>>n;
        cout<<f(n)<<"\n";
	}
	return 0;
}
