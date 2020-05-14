#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree
<pair<int,int>,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 100005

ordered_set bit[mxn];
vector<int> g[mxn];
int a[mxn],b[mxn];
int z=0;
ll ans=0;

void update(int x,int value,int y){
while(x<=z){
    bit[x].insert({value,y});
    x+=x&(-x);
}
}

void del(int x,int value,int y){
while(x<=z){
    bit[x].erase({value,y});
    x+=x&(-x);
}
}

void query(int x,int value){
while(x>0){
    ll z=(ll)bit[x].order_of_key({value,-inf});
    ans+=z;
    x-=x&(-x);
}
}

void dfs(int x,int p){
query(a[x],b[x]);
update(a[x],b[x],x);
for(auto &it:g[x])
    if(it!=p)
        dfs(it,x);
del(a[x],b[x],x);
}

int main(){
sp;
int n,x,y;
cin>>n;
for(int i=1; i<n; ++i){
    cin>>x>>y;
    g[x].pb(y);
    g[y].pb(x);
}
map<int,int> mp;
for(int i=1; i<=n; ++i){
    cin>>a[i];
    mp[a[i]];
}

for(auto &it:mp)it.s=++z;
z=0;
for(int i=1; i<=n; ++i)a[i]=mp[a[i]];
mp.clear();
for(int i=1; i<=n; ++i){
    cin>>b[i];
    mp[b[i]];
}
for(auto &it:mp)it.s=++z;
for(int i=1; i<=n; ++i)b[i]=mp[b[i]];
dfs(1,0);
cout<<ans;
return 0;}
