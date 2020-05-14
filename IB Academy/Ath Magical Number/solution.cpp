#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
//#define mod (long long)1000000007
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

int solveit(int N, int A, int B) {
    long long ab=(1LL*A*B)/__gcd(A,B);
    long long l=1LL,r=(long long)(1e18),m,ans;
    long long mod=1000000007;
    while(l<=r){
        m=(l+r)>>1;
        long long temp=m/A+m/B-m/ab;
        if(temp>=N){
            ans=m;
            r=m-1;
        }
        else
            l=m+1;
        }
    return (int)(ans%mod);
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        assert(a>=1&&a<=1000000000);
        assert(b>=2&&b<=40000);
        assert(c>=2&&c<=40000);
        int ans=solveit(a,b,c);
        cout<<ans<<"\n";
    }
    return 0;
}
