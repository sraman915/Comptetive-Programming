/*
SOLUTION BY RAMAN SHARMA
ORDERSET - Order statistic set
https://www.spoj.com/problems/ORDERSET/
*/

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
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

int tree[4*mxn];

void update(int i,int l,int r,int x,int y){
if(l==r){
    tree[i]=y;
    return;
}
int m=(l+r)>>1;
if(x>=l&&x<=m)update(i+i,l,m,x,y);
else update(i+i+1,m+1,r,x,y);
tree[i]=tree[i+i]+tree[i+i+1];
}

int query(int i,int l,int r,int k){
if(l==r)return l;
int m=(l+r)>>1;
if(tree[i+i]>=k)return query(i+i,l,m,k);
return query(i+i+1,m+1,r,k-tree[i+i]);
}

int query1(int i,int l,int r,int x,int y){
if(l>r||x>y||l>y||x>r)return 0;
if(l>=x&&r<=y)return tree[i];
int m=(l+r)>>1;
return (query1(i+i,l,m,x,y)+query1(i+i+1,m+1,r,x,y));
}

int main(){
sp;
int n;
cin>>n;
map<int,int> mp;
int t[n],x[n];
char y;
for(int i=0; i<n; ++i){
    cin>>y>>x[i];
    if(y!='K')
    mp[x[i]];
    if(y=='I')t[i]=0;
    else if(y=='D')t[i]=1;
    else if(y=='C')t[i]=2;
    else t[i]=3;
}
int z=0;
for(auto &it:mp)
    it.s=++z;
int c[z+1];
for(int i=0; i<n; ++i){
        if(t[i]!=3){
    c[mp[x[i]]]=x[i];
    x[i]=mp[x[i]];
        }
}

for(int i=0; i<n; ++i){
    if(t[i]==0)update(1,1,z,x[i],1);
    else if(t[i]==1)update(1,1,z,x[i],0);
    else if(t[i]==2)cout<<query1(1,1,z,1,x[i]-1)<<"\n";
    else {
        if(tree[1]<x[i])cout<<"invalid\n";
        else cout<<c[query(1,1,z,x[i])]<<"\n";
    }
}
return 0;}
