/*
SOLUTION BY RAMAN SHARMA
MKTHNUM - K-th Number
https://www.spoj.com/problems/MKTHNUM/
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
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
vector<int> tree[2*mxn];
int a[mxn];

void build(int i,int l,int r){
if(l==r){
    tree[i].pb(a[l]);
    return;
}
int m=(l+r)>>1;
build(i+i,l,m),build(i+i+1,m+1,r);
merge(tree[i+i].begin(),tree[i+i].end(),tree[i+i+1].begin(),tree[i+i+1].end(),back_inserter(tree[i]));
}

int query(int i,int l,int r,int x,int y,int k){
if(l>r||x>r||l>y)return 0;
if(l>=x&&r<=y)
    return upper_bound(tree[i].begin(),tree[i].end(),k)-tree[i].begin();
int m=(l+r)>>1;
return query(i+i,l,m,x,y,k)+query(i+i+1,m+1,r,x,y,k);
}

int main(){
sp;
int n,q,x,y,k;
cin>>n>>q;
int b[n+1];
map<int,int> mp;
for(int i=1; i<=n; ++i){
    cin>>a[i];
    mp[a[i]];
}
x=0;
for(auto &it:mp){
        it.s=++x;
b[x]=it.f;
}
for(int i=1; i<=n; ++i)
    a[i]=mp[a[i]];
build(1,1,n);
while(q--){
    cin>>x>>y>>k;
   int ans=1,l,r,m;
   l=1,r=n;
   while(l<=r){
    m=(l+r)>>1;
    if(query(1,1,n,x,y,m)>=k){
        ans=m;
        r=m-1;
    }
    else l=m+1;
   }
   cout<<b[ans]<<"\n";
}
return 0;}
