/*
SOLUTION BY RAMAN SHARMA
POSTERS - Election Posters
https://www.spoj.com/problems/POSTERS/
*/

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
int tree[mxn];
set<int> s;

void push(int i,int l,int r){
if(!tree[i])return;
if(l!=r)tree[i+i]=tree[i+i+1]=tree[i];
tree[i]=0;
}

void update(int i,int l,int r,int x,int y,int val){
if(l>r||x>r||l>y)return;
if(l>=x&&r<=y){
    tree[i]=val;
    return;
}
push(i,l,r);
int m=(l+r)>>1;
update(i+i,l,m,x,y,val),update(i+i+1,m+1,r,x,y,val);
}

void query(int i,int l,int r){
if(tree[i]){
    s.insert(tree[i]);
    return;
}
if(l==r)return;
int m=(l+r)>>1;
query(i+i,l,m),query(i+i+1,m+1,r);
}

int main(){
sp;
int t;
cin>>t;
while(t--){
s.clear();
memset(tree,0,sizeof tree);
int n,x=0;
cin>>n;
int l[n],r[n];
map<int,int> mp;
for(int i=0; i<n; ++i){
    cin>>l[i]>>r[i];
    mp[l[i]];
    mp[r[i]];
}
for(auto &it:mp)it.s=++x;
for(int i=0; i<n; ++i){
    l[i]=mp[l[i]];
    r[i]=mp[r[i]];
}
for(int i=0; i<n; ++i)update(1,1,x,l[i],r[i],i+1);
query(1,1,x);
cout<<s.size()<<"\n";
}
return 0;}
