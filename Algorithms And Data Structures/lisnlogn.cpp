#include<bits/stdc++.h>
using namespace std;

#define int long long
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


int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n;
        vector<int> v;
        vector<int>::iterator it;
        for(int i = 1; i <= n; ++i){
            cin>>x;
            it = lower_bound(v.begin(), v.end(), x);
            if(it == v.end())
                v.push_back(x);
            else
                *it = x;
        }
        cout<<v.size()<<"\n";
    }
    return 0;
}
