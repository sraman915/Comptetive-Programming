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
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; ++i)
        cin>>a[i];
    map<int,int> mp;
    ++mp[a[0]];
    map<int,int> ::iterator it;
    for(int i=1; i<n; ++i){
        it=mp.lower_bound(a[i]);
        if(it==mp.begin())
            ++mp[a[i]];
        else{
            --it;
            int x=it->first;
            int y=it->second;
            mp.erase(it);
            if(y-1>=1)
                mp[x]=y-1;
            mp[a[i]]++;
        }
    }
    int ans=0;
    for(auto &it:mp)
        ans+=it.second;
    cout<<ans;
    return 0;
}
