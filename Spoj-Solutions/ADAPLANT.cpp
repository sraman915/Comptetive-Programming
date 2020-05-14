/*
http://www.spoj.com/problems/ADAPLANT/
SOLUTION BY RAMAN SHARMA
ADAPLANT - Ada and Plants
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
    int n,k;
    cin>>n>>k;
    int a[n+1];
    int ans=INT_MIN;
    multiset<int> s;
    for(int i=1; i<=n; ++i)cin>>a[i];
    for(int i=1; i<=min(n,k+2); ++i){
        s.insert(a[i]);
        ans=max(ans,*s.rbegin()-*s.begin());
    }
    for(int i=k+3; i<=n; ++i){
        s.erase(s.find(a[i-k-2]));
        s.insert(a[i]);
        ans=max(ans,*s.rbegin()-*s.begin());
    }
    cout<<ans<<"\n";
}
return 0;}
