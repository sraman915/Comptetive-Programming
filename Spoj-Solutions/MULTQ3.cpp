/*
MULTQ3 - Multiples of 3
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mxn 100001
struct node{
int a1,a2,a0;
};
node tree[4*mxn],nl;
int ar[mxn],lazy[4*mxn];

node merge(node a,node b){
node c;
c.a0=a.a0+b.a0;
c.a1=a.a1+b.a1;
c.a2=a.a2+b.a2;
return c;
}
node lmerge(node a,int c){
 int x0,x1,x2;
 if(c==1){
    x0=a.a2;
    x1=a.a0;
    x2=a.a1;
 }
 else{
    x0=a.a1;
    x1=a.a2;
    x2=a.a0;
 }
 node cc;
 cc.a0=x0;
 cc.a1=x1;
 cc.a2=x2;
 return cc;
}
void build(int i,int l,int r){
if(l==r){
    tree[i].a0=1;
    return;
}
int m=(l+r)>>1;
build(i+i,l,m);
build(i+i+1,m+1,r);
tree[i]=merge(tree[i+i],tree[i+i+1]);
}
void update(int i,int l,int r,int x,int y){
if(lazy[i]){
tree[i]=lmerge(tree[i],lazy[i]);
if(l!=r){
    lazy[i+i]=(lazy[i+i]+lazy[i])%3;
    lazy[i+i+1]=(lazy[i+i+1]+lazy[i])%3;
}
lazy[i]=0;
}
if(l>r||l>y||r<x)
    return;

if(l>=x&&r<=y){
    tree[i]=lmerge(tree[i],1);
    if(l!=r){
         lazy[i+i]=(lazy[i+i]+1)%3;
    lazy[i+i+1]=(lazy[i+i+1]+1)%3;
    }
    return;
}
int m=(l+r)>>1;
update(i+i,l,m,x,y);
update(i+i+1,m+1,r,x,y);
tree[i]=merge(tree[i+i],tree[i+i+1]);
}

node query(int i,int l,int r,int x,int y){
if(lazy[i]){
tree[i]=lmerge(tree[i],lazy[i]);
if(l!=r){
    lazy[i+i]=(lazy[i+i]+lazy[i])%3;
    lazy[i+i+1]=(lazy[i+i+1]+lazy[i])%3;
}
lazy[i]=0;
}
if(l>r||l>y||r<x)
    return nl;
if(l>=x&&r<=y)
        return tree[i];

int m=(l+r)>>1;
node a=query(i+i,l,m,x,y);
node b=query(i+i+1,m+1,r,x,y);
return merge(a,b);
}


int main(){
    sp;
    memset(tree,0,sizeof tree);
nl.a0=nl.a1=nl.a2=0;
int n,q;
cin>>n>>q;
build(1,1,n);
int i,j,k;
node c;
while(q--){
    cin>>i>>j>>k;
    if(i){
        c=query(1,1,n,j+1,k+1);
        cout<<c.a0<<"\n";
    }
    else
        update(1,1,n,j+1,k+1);
}
return 0;
}
