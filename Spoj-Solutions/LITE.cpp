/*
LITE-LIGHT SWITCHING
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
#define mxn 200005

int tree[4*mxn],lazy[4*mxn];
void update(int i,int l,int r,int x,int y){
if(lazy[i]){
    tree[i]=(r+1-l)-tree[i];
    if(l!=r){
        lazy[i+i]^=lazy[i];
        lazy[i+i+1]^=lazy[i];
    }
    lazy[i]=0;
}
if(l>r||x>r||l>y)
    return;
if(l>=x&&r<=y){
    tree[i]=r+1-l-tree[i];
    if(l!=r){
        lazy[i+i]^=1;
        lazy[i+i+1]^=1;
    }
    return ;
}
int m=(l+r)>>1;
update(i+i,l,m,x,y);
update(i+i+1,m+1,r,x,y);
tree[i]=tree[i+i]+tree[i+i+1];
}

int query(int i,int l,int r,int x,int y){
if(l>r||x>r||l>y)
    return 0;
if(lazy[i]){
    tree[i]=(r-l+1)-tree[i];
    if(l!=r){
        lazy[i+i]^=lazy[i];
        lazy[i+i+1]^=lazy[i];
    }
    lazy[i]=0;
}
if(l>=x&&r<=y) return tree[i];
int m=(l+r)>>1;
return(query(i+i,l,m,x,y)+query(i+i+1,m+1,r,x,y));
}

int main(){
   sp;
int n,m,l,r,c;
cin>>n>>m;
while(m--){
    cin>>c>>l>>r;
    if(c)
        cout<<query(1,1,n,l,r)<<"\n";
    else update(1,1,n,l,r);
}
return 0;}
