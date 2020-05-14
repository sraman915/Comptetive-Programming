#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 1000100

ll const lgn=21,mask=1LL<<21;
ll a[mask],b[mask],dp[mask];

ll nc2(ll n){
return (n*(n-1)*1LL)/2;
}

int32_t main(){
int t;
cin>>t;
while(t--){
    memset(b,0,sizeof b);
    int n,x;
    ll ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
    cin>>x;
    ++b[x];}
    for(int i=0;i<mask;i++)
        dp[i]=b[i];
    for(int i=0;i<lgn;i++)
        for(int j=0;j<mask;j++)
            if((j&(1<<i))==0&&(j|(1<<i))<mask)
                dp[j|(1<<i)]+=dp[j];

    for(int i=0 ; i<mask ; i++){
			ans+=b[i]*dp[i];
			ans-=b[i]*b[i];
			ans+=nc2(b[i]);
		}
		cout<<ans<<"\n";
	}

return 0;}
