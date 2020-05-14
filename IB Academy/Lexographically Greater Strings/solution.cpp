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

const long long MOD =1000000007;

long long dp[3][2005][2005];

int doit(int n,int k,string &s){
    for(int i=0; i<3;++i)
        for(int j=0; j<=n; ++j)
            for(int pp=0; pp<=k; ++pp)
                    dp[i][j][pp]=0;
    dp[1][0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			long long p_sum = 0;
			for(int k=0;k<3;k++)
                p_sum += dp[k][i-1][j];
			p_sum %= MOD;
			dp[0][i][j]=p_sum;
			dp[1][i][j]=(s[i-1]-'a')*p_sum%MOD;
			dp[2][i][j]=0;
			long long add = n-i+1;
			for(int prev=i;prev>0;prev--){
				if(add>j) break;
				dp[2][i][j]+=(26-(s[i-1]-'a'+1))*(dp[1][prev-1][j-add]+dp[2][prev-1][j-add])%MOD;
				if(dp[2][i][j]>=MOD)
                    dp[2][i][j]-=MOD;
				add += n-i+1;
			}
		}
	}

	long long ans = 0;
	for(int i=0;i<3;i++)
        ans += dp[i][n][k];
	ans %= MOD;
	return (int)(ans);
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,k;
string s;
cin>>n>>k>>s;
assert(n>=1&&n<=2000);
assert(k>=0&&k<=2000);
assert(s.size()==n);
for(auto &it:s)
    assert(it>='a'&&it<='z');
int ans=doit(n,k,s);
cout<<ans<<"\n";
}
return 0;}
