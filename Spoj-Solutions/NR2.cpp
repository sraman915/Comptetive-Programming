/*

NR2 - Bhagat The Bit Man
https://www.spoj.com/problems/NR2/
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
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
#define mxn 200005


int main(){
sp;
int n;
cin>>n;
int a[64]={0};
ll x;
for(int i=0; i<n; ++i){
    cin>>x;
    for(ll j=0; j<64; ++j)
        if((x>>j)&1)++a[j];
}
ll ans=0;
for(ll i=0; i<64; ++i)
    if(a[i]!=0&&a[i]!=n)ans|=(1LL<<i);
cout<<ans;
return 0;}
