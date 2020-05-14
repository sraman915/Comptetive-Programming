/*
http://www.spoj.com/problems/UPDATEIT/
SOLUTION  BY RAMAN SHARMA
UPDATEIT - Update the array !
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
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
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005


int main(){
sp;
int t;
cin>>t;
while(t--){
int n,u,q,l,r;
ll val;
cin>>n>>u;
ll a[n+1];
memset(a,0,sizeof a);
while(u--){
    cin>>l>>r>>val;
    a[l]+=val;
    a[r+1]-=val;
}
for(int i=1; i<n;++i)
    a[i]+=a[i-1];
cin>>q;
while(q--){
    cin>>l;
    cout<<a[l]<<"\n";
}
}
return 0;}
