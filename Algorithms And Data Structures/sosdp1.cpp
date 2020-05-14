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

int a[mxn];
int k=(1<<19)-1;


int main(){
sp;
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int c[n];
    memset(a,0,sizeof a);
    for(int i=0; i<n; ++i){
        cin>>c[i];
        a[c[i]]++;
    }
    for(int i=0; i<20; ++i)
    for(int j=0; j<mxn; ++j){
        if(j&(1<<i))
            a[j]+=a[j^(1<<i)];
    }
    ll ans=0;
    for(int i=0; i<n; ++i)
        ans+=1LL*a[k^c[i]];
    cout<<ans<<"\n";
}

return 0;}
