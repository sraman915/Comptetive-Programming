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

int SumoOMaxOddDivisorsUptoN(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int  k=(n+1)/2;
    return ((1LL*k*k)%mod+SumoOMaxOddDivisorsUptoN(n>>1))%mod;
}

int solveit(int a,int b){
    int x2=SumoOMaxOddDivisorsUptoN(b);
    int x1=SumoOMaxOddDivisorsUptoN(a-1);
    int ans=x2-x1;
    while(ans<0)
        ans=ans+mod;
    while(ans>=mod)
        ans=ans-mod;
    return ans;
}


int32_t main(){
sp;
freopen("input2.txt","r",stdin);
freopen("output2.txt","w",stdout);
int t;
cin>>t;
while(t--){
int a,b;
cin>>a>>b;
assert(a>=1&&a<=1000000000);
assert(b>=1&&b<=1000000000);
cout<<solveit(a,b)<<"\n";
}
return 0;}
