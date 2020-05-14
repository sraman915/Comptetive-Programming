/*
GSS1-Can you answer these queries!
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mxn 50001
ll a[mxn];
struct node{
    ll sum,pref,suff,ans;
    };
node tree[4*mxn],nl;
node combine(node a,node b){
node x;
x.sum=a.sum+b.sum;
x.pref=max(a.pref,a.sum+b.pref);
x.suff=max(b.suff,b.sum+a.suff);
x.ans=max(max(a.ans,b.ans),a.suff+b.pref);
return x;
}
void build(int i,int l,int r){
if(l==r){
    tree[i].sum=a[l];
    tree[i].ans=tree[i].pref=tree[i].suff=a[l];
    return;
}
int m=(l+r)/2;
build(i+i,l,m);
build(i+i+1,m+1,r);
tree[i]=combine(tree[i+i],tree[i+i+1]);
}
node query(int i,int l,int r,int x,int y){
if(l>r||l>y||r<x)
    return nl;
if(l>=x&&r<=y)
    return tree[i];
int m=(l+r)/2;
return combine(query(i+i,l,m,x,y),query(i+i+1,m+1,r,x,y));
}
int main(){
    ll neg=-15008;
	nl.sum=neg;
	nl.pref=neg;
	nl.ans=neg;
	nl.suff=neg;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
        scanf("%lld",a+i);
    build(1,1,n);
    int q,x,y;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&x,&y);
        node z=query(1,1,n,x,y);
        printf("%lld\n",z.ans);
    }
return 0;}
