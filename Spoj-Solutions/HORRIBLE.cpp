/*
HORRIBLE - Horrible Queries
SOLUTION BY-RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=300001;
ll tree[4*mxn],lazy[4*mxn];
void update(ll i,ll start,ll end,ll l,ll r,ll val){
if(lazy[i]!=0){
    tree[i]+=((end-start+1)*lazy[i]);
    if(start!=end){
        lazy[i+i]+=lazy[i];
        lazy[i+i+1]+=lazy[i];
    }
    lazy[i]=0;
}
if(start>end||start>r||end<l)
    return;
if(start>=l&&end<=r){
        tree[i]+=((end-start+1)*val);
    if(start!=end){
        lazy[i+i]+=val;
        lazy[i+i+1]+=val;
    }
    return;
}
ll m=(start+end)/2;
update(i+i,start,m,l,r,val);
update(i+i+1,m+1,end,l,r,val);
tree[i]=tree[i+i]+tree[i+i+1];
}
ll query(ll i,ll start,ll end,ll l,ll r){
if(start>end||start>r||end<l)
    return 0;
if(lazy[i]!=0){
    tree[i]+=((end-start+1)*lazy[i]);
    if(start!=end){
        lazy[i+i]+=lazy[i];
        lazy[i+i+1]+=lazy[i];
    }
    lazy[i]=0;
}
if(start>=l&&end<=r)
    return tree[i];
ll m=(start+end)/2;
return (query(i+i,start,m,l,r)+query(i+i+1,m+1,end,l,r));
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,c;
      memset(tree,0,sizeof(tree));
      memset(lazy,0,sizeof(lazy));
        scanf("%lld%lld",&n,&c);
        ll ch,p,q;
        ll val;
        while(c--){
            scanf("%lld",&ch);
            if(ch){p=0,q=0;
                    scanf("%lld%lld",&p,&q);
                printf("%lld\n",query(1,1,n,p,q));
            }
            else{p=0,q=0,val=0;
                scanf("%lld%lld%lld",&p,&q,&val);
                update(1,1,n,p,q,val);
            }
        }
    }
return 0;}
