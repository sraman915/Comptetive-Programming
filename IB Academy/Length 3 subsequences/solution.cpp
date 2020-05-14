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

int countsubsequences(vector<int> &a,int m){

int n=a.size();
assert(n>=1&&n<=100000);
assert(m>=1&&m<=1000);

int cnt[m];

memset(cnt,0,sizeof cnt);

for(int i=0; i<n; ++i){
    assert(a[i]>=1 && a[i] <=1000000000);
    int y=a[i]%m;
    ++cnt[y];
}

int ans=0;

for(int i=0; i<m; ++i){
     for(int j=i; j<m; ++j){
          int rem=(m-(i+j)%m)%m;
          if (rem<j)continue;
          if(i==j && rem==j){
             int x=1LL*(cnt[i]*(cnt[i]-1)*(cnt[i]-2))/6;
             x%=mod;
             ans=(ans+x)%mod;
          }

         else if (i==j){
            int x=(1LL*cnt[i]*(cnt[i]-1)*cnt[rem])/2;
            x%=mod;
            ans=(ans+x)%mod;
          }
         else if (i==rem){
            int x=(1LL*cnt[i]*(cnt[i]-1)*cnt[j])/2;
            x%=mod;
            ans=(ans+x)%mod;
          }
        else if (j==rem){
            int x=(1LL*cnt[j]*(cnt[j]-1)*cnt[i])/2;
            x%=mod;
            ans=(ans+x)%mod;
          }
       else{
           int x=(1LL*cnt[j]*cnt[i]*cnt[rem]);
           x%=mod;
           ans=(ans+x)%mod;
          }
    }
}

return ans;

}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m;
cin>>n;
vector<int> a(n);
for(int i=0; i<n; ++i)cin>>a[i];
cin>>m;
int ans=countsubsequences(a,m);
cout<<ans<<"\n";
}
return 0;}
