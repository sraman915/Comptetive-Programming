/*
SOLUTION BY RAMAN SHARMA
ORDSUM23 - Sums of 2 and 3
https://www.spoj.com/problems/ORDSUM23/
*/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define mxn 1000005

ll ans[mxn],n;
void pre(){
ans[2]=ans[3]=1LL;
for(int i=4; i<mxn; ++i)
    ans[i]=(ans[i-2]+ans[i-3])%mod;
}

int main(){
sp;
int t;
cin>>t;
pre();
while(t--){
    cin>>n;
    cout<<ans[n]<<"\n";
}
return 0;}
