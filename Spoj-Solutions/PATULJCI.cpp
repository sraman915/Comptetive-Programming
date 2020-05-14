/*
PATULJCI - Snow White and the N dwarfs
SOLUTION BY RAMAN SHARMA
*/

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
#define mxn 100005


int main() {
sp;
int n,c,x,l,r,q;
cin>>n>>c;
int a[n+1];
vector<int> v[n+1];
for(int i=1; i<=n; ++i){
    cin>>a[i];
    v[a[i]].pb(i);
}
cin>>q;
while(q--){
     cin>>l>>r;
     int z=0,y;
     for(int i=0; i<30; ++i){
    x=l+rand()%(r+1-l);
     y=a[x];
    int need=upper_bound(v[y].begin(),v[y].end(),r)-lower_bound(v[y].begin(),v[y].end(),l);

    if(need+need>r+1-l){
        z=1;
        break;
    }}
    if(z)
        cout<<"yes "<<y<<"\n";
    else cout<<"no\n";
}

return 0;}


