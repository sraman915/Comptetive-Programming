/*
SOLUTION BY RAMAN SHARMA
ADACOINS - Ada and Coins
https://www.spoj.com/problems/ADACOINS/
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
#define mxn 100005

bitset<mxn> a;


int main(){
sp;
int x,n,q,l,r;
a[0]=1;
cin>>n>>q;
for(int i=1; i<=n; ++i){
    cin>>x;
    a|=a<<x;
}
int c[mxn];
memset(c,0,sizeof c);
for(int i=1; i<mxn; ++i)
    c[i]=c[i-1]+a[i];
while(q--){
    cin>>l>>r;
    cout<<c[r]-c[l-1]<<"\n";
}
return 0;}
