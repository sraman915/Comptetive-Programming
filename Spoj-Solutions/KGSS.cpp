/*
KGSS - Maximum Sum
SOLUITON BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 100005
#define ll long long
struct node{
ll m1,m2;
};
ll a[mxn];
node tree[4*mxn],nl;
node combine(node a,node b){
node c;
c.m1=max(a.m1,b.m1);
c.m2=max(a.m2,max(a.m1+b.m1-c.m1,b.m2));
return c;
}
void build(int i,int l,int r){
if(l==r){
    tree[i].m1=a[l];
    tree[i].m2=0;
    return;
}
int m=(l+r)/2;
build(i+i,l,m);
build(i+i+1,m+1,r);
tree[i]=combine(tree[i+i],tree[i+i+1]);
}
void update(int i,int l,int r,int idx,ll val){
if(l==r){
    a[idx]=val;
    tree[i].m1=val;
    tree[i].m2=0;
    return;
}
int m=(l+r)/2;
if(idx>=l&&idx<=m)
    update(i+i,l,m,idx,val);
else
    update(i+i+1,m+1,r,idx,val);
tree[i]=combine(tree[i+i],tree[i+i+1]);
}
node query(int i,int l,int r,int x,int y){
if(l>y||l>r||x>r)
    return nl;
if(l>=x&&r<=y)
    return tree[i];
int m=(l+r)/2;
node p1=query(i+i,l,m,x,y);
node p2=query(i+i+1,m+1,r,x,y);
return combine(p1,p2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
nl.m1=-10000;
nl.m2=-10000;
int n,q;
cin>>n;
for(int i=1; i<=n; ++i)
    cin>>a[i];
build(1,1,n);
cin>>q;
char ch;
int x,y;
node c;
for(int i=0; i<q; ++i){
 cin>>ch>>x>>y;
    if(ch=='Q'){
        c=query(1,1,n,x,y);
        printf("%d\n",c.m1+c.m2);
    }
    else{
        update(1,1,n,x,1LL*y);
    }
}
return 0;}
