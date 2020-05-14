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


int solveit(vector<int> &a){
    int n=a.size();
    int ans1=0,ans2=0;
    int x=1,y=0;
    for(auto &it:a){
        it=(it&1);
        if(it==x){
            ++ans1;
            x^=1;
        }
        if(it==y){
            y^=1;
            ++ans2;
        }
    }
    return max(ans1,ans2);
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        assert(n>=1&&n<=100000);
        vector<int> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
            assert(a[i]>=1&&a[i]<=1000000000);
        }
        int ans=solveit(a);
        cout<<ans<<"\n";
    }
    return 0;
}
