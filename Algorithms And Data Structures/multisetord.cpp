#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
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
#define mxn 500005


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree
<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ordered_set m;

int32_t main(){
sp;
    int n,q;
    cin>>n>>q;
    int a[n+1];
    for(int i=1; i<=n; ++i){
        cin>>a[i];
        m.insert(a[i]);
    }
    char ch;
    int x,y;
    while(q--){
        cin>>ch>>x>>y;
        if(ch=='?')
            cout<<(m.order_of_key(y+1)-m.order_of_key(x))<<"\n";
        else{
            m.erase(m.find_by_order(m.order_of_key(a[x])));
            m.insert(y);
            a[x]=y;
        }
    }
    return 0;
}
