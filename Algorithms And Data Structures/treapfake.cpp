#include<bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
#define pi pair<double,double>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005



struct node{
    int a,b;
    node(int aa,int bb){
        a=aa;
        b=bb;}
    bool operator <(const node& other) const {
		if(a==other.a) return b<other.b;
        return a>other.a;
	}
};

typedef tree <node, null_type, less<node>, rb_tree_tag, tree_order_statistics_node_update> orderset;

orderset s;

int main(){
sp;
int n=5;
cin>>n;
vector<int> v;
v.pb(0);
int x;
for(int i=1; i<=n; ++i){
    cin>>x;
    v.pb(x);
    s.insert(node(x,i));
}

for(int i=0; i<5; ++i){
node p=*s.find_by_order(i);
cout<<p.a<<" "<<p.b<<"\n";
}

s.erase(node(v[1],1));

for(int i=0; i<4; ++i){
node p=*s.find_by_order(i);
cout<<p.a<<" "<<p.b<<"\n";
}

for(int i=2; i<=5; ++i){
    int z=s.order_of_key(node(v[i],i));
    cout<<z<<"\n";
}

if(s.find(node(5,5))!=s.end())cout<<"YES";
else cout<<"NO";

return 0;}
