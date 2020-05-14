#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define inf 1000000000
#define mxn 100010
ll table[4*mxn][20],a[mxn],tree[4*mxn],lazy[4*mxn];

void push(int i,int l,int r){
if(lazy[i]){
    ll s=0;
    for(int j=0; j<20; ++j){
        if(lazy[i]&(1<<j))
            table[i][j]=r+1-l-table[i][j];
    s+=(1LL<<j)*table[i][j];
}
tree[i]=s;
if(l!=r){
    lazy[i+i]^=lazy[i];
    lazy[i+i+1]^=lazy[i];
}
lazy[i]=0;
}
}
void build(int i,int l,int r){
if(l==r){
        tree[i]=a[l];
    for(int j=0; j<20; ++j)
        table[i][j]=(a[l]>>j)&1;
    return ;
}
int m=(l+r)>>1;
build(i+i,l,m);
build(i+i+1,m+1,r);
for(int j=0; j<20; ++j)
    table[i][j]=table[i+i][j]+table[i+i+1][j];
tree[i]=tree[i+i+1]+tree[i+i];
}

void update(int i,int l,int r,int x,int y,int val){
push(i,l,r);
if(l>r||l>y||r<x)
    return;
if(l>=x&&r<=y){
    lazy[i]^=val;
    push(i,l,r);
    return;
}
int m=(l+r)>>1;
update(i+i,l,m,x,y,val);
update(i+i+1,m+1,r,x,y,val);
for(int j=0; j<20; ++j)
    table[i][j]=table[i+i][j]+table[i+i+1][j];
tree[i]=tree[i+i]+tree[i+i+1];
}
ll query(int i,int l,int r,int x,int y){
push(i,l,r);
if(l>r||l>y||r<x)
    return 0LL;
if(l>=x&&r<=y)
    return tree[i];
int m=(l+r)>>1;
return (query(i+i,l,m,x,y)+query(i+i+1,m+1,r,x,y));
}

int main(){
    sp;
int n,q,l,r,c,x;
cin>>n;
for(int i=1; i<=n; ++i) cin>>a[i];
build(1,1,n);
cin>>q;
while(q--){
    cin>>c;
    if(c==1){
        cin>>l>>r;
        cout<<query(1,1,n,l,r)<<"\n";
    }
    else{
        cin>>l>>r>>x;
        update(1,1,n,l,r,x);
    }
}
return 0;}
