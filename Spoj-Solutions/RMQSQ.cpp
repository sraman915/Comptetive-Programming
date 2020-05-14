/*
RMQSQ-Range minimum query
solution by RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mx 100001
long inf=1000000001;
long a[mx],tree[4*mx];
void build(int i,int l,int r){
    if(l>r)
        return;
if(l==r){
    tree[i]=a[l];
    return;
}
int m=(l+r)/2;
build(i+i+1,l,m);
build(i+i+2,m+1,r);
tree[i]=min(tree[i+1+i],tree[i+i+2]);
}
int query(int i,int l,int r,int x,int y){
    if(l>y||l>r||x>r)
        return inf;
    if(l>=x&&y>=r)
        return tree[i];
        int mid=(l+r)/2;
    return (min(query(2*i+1,l,mid,x,y),query(i+2+i,mid+1,r,x,y)));
}
int main(){
int n;
scanf("%d",&n);
for(int i=1; i<=n; ++i)
    scanf("%ld",a+i);
build(1,1,n);
int q,x,y;
scanf("%d",&q);
while(q--){
    scanf("%d%d",&x,&y);
    printf("%ld\n",query(1,1,n,x+1,y+1));
}
return 0;
}
