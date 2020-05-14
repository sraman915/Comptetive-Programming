/*
ETFS - Euler Totient Function Sieve
SOLUTION BY RAMAN SHARMA
http://www.spoj.com/problems/ETFS/
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
#define mxn 10000005
ll ph[mxn];
vector<int> p;

void pre(){
for(int i=1;i<mxn; ++i)ph[i]=i;
for(int i=2; i<mxn; ++i)
if(ph[i]==i){
    p.pb(i);
    for(int j=i; j<mxn; j+=i){
        ph[j]/=i;
        ph[j]*=(i-1);
    }
}

}
ll p1[100005],p2[100005];

int main(){
sp;
pre();
ll a,b;
cin>>a>>b;
if(b<mxn){
    for(int i=a; i<b+1; ++i)
        cout<<ph[i]<<"\n";
    return 0;
}
int n=p.size();
for(ll i=a; i<=b; ++i)
    p1[i-a]=i,p2[i-a]=i;
for(int i=0; i<n; ++i){
    ll y=1LL*p[i];
    for(ll j=((a-1)/y+1)*y; j<=b; j+=y){
        while(p2[j-a]%y==0)
            p2[j-a]/=y;
        p1[j-a]/=y;
        p1[j-a]*=(y-1);
    }
}
for(ll i=a; i<=b; ++i){
    if(p[i-a]==i){
        p[i-a]=i-1;
        continue;
    }
    if(p2[i-a]>1){
        p1[i-a]/=p2[i-a];
        p1[i-a]*=(p2[i-a]-1);
    }
}
for(ll i=a; i<=b;++i)
    cout<<p1[i-a]<<"\n";
return 0;}
