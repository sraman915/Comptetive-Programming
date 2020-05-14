/*
SOLUTION BY RAMAN SHARMA
KQUERY - K-query
https://www.spoj.com/problems/KQUERY/
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
#define mxn 100005
int ans[mxn+mxn],b[mxn],tree[4*mxn];

struct node{
int id,l,r,k;
};

node c[mxn*4];

void build(int i,int l,int r){
if(l==r){
    tree[i]=1;
    return;
}
int m=(l+r)>>1;
build(i+i,l,m),build(i+i+1,m+1,r);
tree[i]=tree[i+i]+tree[i+i+1];
}

void update(int i,int l,int r,int x){
if(l==r){
    tree[i]=0;
    return;
}
int m=(l+r)>>1;
if(x>=l&&x<=m)update(i+i,l,m,x);
else update(i+i+1,m+1,r,x);
tree[i]=tree[i+i]+tree[i+i+1];
}

int query(int i,int l,int r,int x,int y){
if(l>r||x>r||l>y||x>y)return 0;
if(l>=x&&r<=y)return tree[i];
int m=(l+r)>>1;
return query(i+i,l,m,x,y)+query(i+i+1,m+1,r,x,y);
}

bool compare(node a,node b){
return a.k<b.k;
}

int main(){
sp;
int n,q;
cin>>n;
pi v[n+1];
for(int i=1; i<=n; ++i){
    cin>>v[i].f;
    v[i].s=i;
}
sort(v+1,v+1+n);
cin>>q;
for(int i=0; i<q; ++i){
    cin>>c[i].l>>c[i].r>>c[i].k;
    c[i].l;
    c[i].r;
    c[i].id=i;
}
sort(c,c+q,compare);
build(1,1,n);
int y=1,x;
for(int i=0; i<q; ++i){
    x=c[i].id;
    while(y<=n&&v[y].f<=c[i].k){
        update(1,1,n,v[y].s);
     ++y;
    }
    ans[x]=query(1,1,n,c[i].l,c[i].r);
}
for(int i=0; i<q; ++i)cout<<ans[i]<<"\n";
return 0;}
