/*
CNTPRIME - Counting Primes
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
#define mxn 1000005
vector<bool> p(mxn);
int a[10005],tree[4*10005],lazy[4*10005];

void sieve(){
p[0]=p[1]=1;
for(int i=4; i<mxn; i+=2)p[i]=1;
for(int i=3; i*i<=mxn; i+=2)
    if(!p[i])for(int j=i*i; j<mxn; j+=2*i)p[j]=1;
}

void build(int i,int l,int r){
if(l==r){
    tree[i]=(p[a[l]]==0);
    return;
}
int m=(l+r)>>1;
build(i+i,l,m),build(i+i+1,m+1,r);
tree[i]=tree[i+i]+tree[i+i+1];
}

void update(int i,int l,int r,int x,int y,int v){
if(lazy[i]){
        if(lazy[i]==2)
           tree[i]=0;
        else tree[i]=r+1-l;
    if(l!=r){
        lazy[i+i]=lazy[i];
        lazy[i+i+1]=lazy[i];
    }
    lazy[i]=0;
}
if(l>r||x>r||l>y) return;
if(l>=x&&r<=y){
    if(p[v]){
        tree[i]=0;
        if(l!=r){
        lazy[i+i]=2;
        lazy[i+i+1]=2;
        }
    }
    else{
        tree[i]=r+1-l;
        if(l!=r){
        lazy[i+i]=1;
        lazy[i+i+1]=1;
        }
    }
    return;
}
int m=(l+r)>>1;
update(i+i,l,m,x,y,v);
update(i+i+1,m+1,r,x,y,v);
tree[i]=tree[i+i]+tree[i+i+1];
}

int query(int i,int l,int r,int x,int y){
if(l>r||x>r||l>y) return 0;
if(lazy[i]){
        if(lazy[i]==2)
           tree[i]=0;
        else tree[i]=r+1-l;
    if(l!=r){
        lazy[i+i]=lazy[i];
        lazy[i+i+1]=lazy[i];
    }
    lazy[i]=0;
}
if(l>=x&&r<=y)return tree[i];
int m=(l+r)>>1;
return (query(i+i,l,m,x,y)+query(i+i+1,m+1,r,x,y));
}
int main(){
   sp;
sieve();
int t;
cin>>t;
for(int j=1; j<=t; ++j){
        cout<<"Case "<<j<<":\n";
    int n,m,c,x,y,v;
    cin>>n>>m;
    for(int i=1; i<=n; ++i) cin>>a[i];
    memset(lazy,0,sizeof lazy);
    memset(tree,0,sizeof tree);
    build(1,1,n);
    while(m--){
        cin>>c>>x>>y;
        if(c) cout<<query(1,1,n,x,y)<<"\n";
        else{cin>>v;
                update(1,1,n,x,y,v);
        }
    }
}
return 0;}
