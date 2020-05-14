/*
COURAGE - Living with Courage
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define mp make_pair
#define f first
#define s second
#define pi pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mxn 100005
ll inf =(1LL<<48LL);
ll a[mxn];
pi tree[4*mxn];

void build(int i,int l,int r){
if(l==r){
tree[i].f=a[l];
tree[i].s=a[l];
return;
}
int m=(l+r)>>1;
build(i+i,l,m);
build(i+i+1,m+1,r);
tree[i].f=min(tree[i+i].f,tree[i+i+1].f);
tree[i].s=tree[i+i].s+tree[i+i+1].s;
}
void update(int i,int l,int r,int x,ll val){
if(l==r){
    a[l]+=val;
    tree[i].f=a[l];
    tree[i].s=a[l];
    return;
}
int m=(l+r)>>1;
if(x>=l&&x<=m)
    update(i+i,l,m,x,val);
else
    update(i+i+1,m+1,r,x,val);
tree[i].f=min(tree[i+i].f,tree[i+i+1].f);
tree[i].s=tree[i+i].s+tree[i+i+1].s;
}
pi query(int i,int l,int r,int x,int y){
if(l>r||r<x||l>y)
    return(mp(LONG_MAX,0LL));
if(l>=x&&r<=y)
    return tree[i];
int m=(l+r)>>1;
pi p1=query(i+i,l,m,x,y);
pi p2=query(i+i+1,m+1,r,x,y);
return mp(min(p1.f,p2.f),p1.s+p2.s);
}
int main(){
sp;
int n;
cin>>n;
for(int i=0; i<n; ++i)cin>>a[i];
build(1,0,n-1);
int q,x,y;
cin>>q;
string s;
while(q--){
    cin>>s>>x>>y;
    if(s[0]=='C'){
        pi b=query(1,0,n-1,x,y);
        cout<<b.s-b.f<<"\n";
    }
    else if(s[0]=='G')
        update(1,0,n-1,y,x);
    else
        update(1,0,n-1,y,-x);
}
return 0;}
