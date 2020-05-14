/*
SOLUTION BY RAMAN SHARMA
TRIPINV - Mega Inversions
https://www.spoj.com/problems/TRIPINV/
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
#define mxn 100005

ll b1[mxn],b2[mxn];

ll read(int x,ll *bit){
int s=0;
while(x>0){
    s+=bit[x];
    x-=(x&(-x));
}
return s;
}

void update(int x,ll val,ll *bit){
while(x<mxn){
    bit[x]+=val;
    x+=x&(-x);
}
}

int main(){
sp;
int n;
cin>>n;
int a[n+1];
for(int i=1; i<=n; ++i){
    cin>>a[i];
    update(a[i],1,b1);
}
ll ans=0;
for(int i=1; i<=n; ++i){
    ll x1=read(n,b2)-read(a[i],b2);
    ll x2=read(a[i]-1,b1);
    ans+=1LL*x1*x2;
    update(a[i],1,b2);
    update(a[i],-1,b1);
}
cout<<ans;
return 0;}
