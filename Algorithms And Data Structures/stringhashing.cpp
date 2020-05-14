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

const int P1 = 29;
const int P2 = 31;


struct Hashs{
	vector<int> hashs;
	vector<int> pows;
	int P;
	int MOD;
	Hashs() {
        P = 29;
        MOD = mod;
	}

	Hashs(string &s, int P, int MOD) : P(P), MOD(MOD){
		int n = s.size();
		pows.resize(n+1, 0);
		hashs.resize(n+1, 0);
		pows[0] = 1;
		for(int i=n-1;i>=0;i--){
			hashs[i]=(1LL * hashs[i+1] * P + s[i] - 'a' + 1) % MOD;
			pows[n-i]=(1LL * pows[n-i-1] * P) % MOD;
		}
		pows[n] = (1LL * pows[n-1] * P)%MOD;
	}
	int get_hash(int l, int r){
		int ans=hashs[l] + MOD - (1LL*hashs[r+1]*pows[r-l+1])%MOD;
		ans%=MOD;
		return ans;
	}
};


int n;
string s;
Hashs h1, h2;

int check(int x){
	map<pair<int, int> , vector<int> > m;
	for(int i = 0; i + x - 1 < s.size(); i++){
		int hash1 = h1.get_hash(i, i + x - 1);
		int hash2 = h2.get_hash(i, i + x - 1);
		m[{hash1, hash2}].push_back(i);
	}
	for(auto &it:m){
		int lo = it.second[0];
		int hi = it.second.back();
		if(hi - lo >= x)
			return 1;
	}
	return 0;
}

int binsearch(int lo, int hi){
	while(lo < hi){
		int mid = (lo + hi + 1) / 2;
		if(check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}

int32_t main(){
sp;
	cin>>n>>s;
	h1 = Hashs(s, P1, mod);
	h2 = Hashs(s, P2, mod);
	int ans = binsearch(0, n / 2);
	cout << ans;
	return 0;
}
