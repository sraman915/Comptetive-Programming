#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define priority_queue pq
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 1000005
ll a[mxn];
vector<ll> p;
void pre(){
for(ll i=1; i<mxn; ++i)a[i]=i;
for(ll i=2; i<mxn; ++i)
if(a[i]==i){
        p.pb(i);
    for(int j=i; j<mxn; j+=i){
        a[j]/=i;
        a[j]*=(i-1);
    }}
}

ll p1[100005],p2[100005];

int main(){
sp;
pre();
int t;
cin>>t;
int n=p.size();
while(t--){
    ll l,r,k;
    cin>>l>>r>>k;
    if(r<mxn){
        int ans=0;
        for(int i=l; i<=r; ++i)
            if(a[i]%k==0)++ans;
     cout<<fixed<<setprecision(6)<<double(ans)/double(r+1-l)<<"\n";
        continue;
    }
    for(ll i=l; i<=r; ++i)
        p1[i-l]=i,p2[i-l]=i;
        for(ll i=0; i<n; ++i){
            ll y=((l-1)/p[i]+1)*p[i];
            for(ll j=y; j<=r; j+=p[i]){
                while(p2[j-l]%p[i]==0){
                    p2[j-l]/=p[i];
                }
                p1[j-l]/=p[i];
                p1[j-l]*=(p[i]-1);
            }
        }
        ll ans=0;
        for(ll i=l; i<=r; ++i){
            if(p1[i-l]==i){
                p1[i-l]=i-1;
                if(p1[i-l]%k==0)++ans;
                continue;
            }
            if(p2[i-l]!=1){
                p1[i-l]/=p2[i-l];
                p1[i-l]*=(p2[i-l]-1);
            }
            if(p1[i-l]%k==0)++ans;
        }
        cout<<fixed<<setprecision(6)<<double(ans)/double(r+1-l)<<"\n";
}
return 0;}
