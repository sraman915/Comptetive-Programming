/*
http://www.spoj.com/problems/ETFD/
SOLUTION BY RAMAN SHARMA
ETFD - Euler Totient Function Depth

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
#define mxn 1000005
vector<int> g[mxn];
int p[mxn],d[mxn];

void pre(){
for(int i=1; i<mxn; ++i)p[i]=i;
for(int i=2; i<mxn; ++i)
    if(p[i]==i)
for(int j=i; j<mxn; j+=i){
    p[j]/=i;
    p[j]*=(i-1);
}
d[1]=0;
for(int i=2; i<mxn; ++i)
    d[i]=d[p[i]]+1;
for(int i=1; i<mxn; ++i)
    g[d[i]].pb(i);
}


int main(){
sp;
pre();
int t;
cin>>t;
while(t--){
    int n,m,k;
    cin>>m>>n>>k;
    cout<<upper_bound(g[k].begin(),g[k].end(),n)-lower_bound(g[k].begin(),g[k].end(),m)<<"\n";
}
return 0;}
