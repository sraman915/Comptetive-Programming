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

int mx=1000000000;

int bruteforce(vector<int> &a,int k){
    int n=a.size();
    int ans=0;
    for(int i=0; i<n; ++i){
        int temp=0;
        int y=0;
        for(int j=i; j<n; ++j){
            temp+=a[j];
            y^=1;
            if(y&&temp>k)
                ++ans;
            if(y==0&&temp<k)
                ++ans;
        }
    }
    return ans;
}


int32_t main(){
sp;
    //freopen("input1.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        assert(n>=1&&n<=100000);
        vector<int> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
            assert(a[i]>=1&&a[i]<=10000);
        }
        int k;
        cin>>k;
        assert(k>=1&&k<=1000000000);
        int ans=bruteforce(a,k);
        cout<<ans<<"\n";
    }
    return 0;
}

