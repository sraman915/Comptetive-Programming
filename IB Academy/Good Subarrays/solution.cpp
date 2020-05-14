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

int mx = 1000000000;

int solveit(vector<int> &a,int k){
    int n=a.size();
    int b[n+1];
    memset(b,0,sizeof b);
    for(int i=1; i<=n; ++i)
        b[i]=b[i-1]+a[i-1];
    int ans=0;
    for(int i=1; i<=n&&ans<mx; ++i){//even subarray sum needs to less than k
        int l=i,r=n,m,z=0;
       while(l<=r){
            int m=(l+r)>>1;
            int sum=b[m]-b[i-1];
            if(sum<k){
                l=m+1;
                z=m+1-i;
            }
            else
                r=m-1;
        }
        ans+=z/2;
    }
    vector<int> odd,even;
    for(int i=1; i<=n; ++i){
        if(i&1)
            odd.push_back(i);
        else
            even.push_back(i);
    }
    for(int i=0; i<odd.size()&&ans<mx; ++i){
        int l=i,r=odd.size()-1,m,z=0;
        while(l<=r){
            m=(l+r)>>1;
            int sum=b[odd[m]]-b[odd[i]-1];
            if(sum>k){
                r=m-1;
                z=odd.size()-m;
            }
            else
                l=m+1;
        }
        ans+=z;
    }
    for(int i=0; i<even.size()&&ans<mx; ++i){
        int l=i,r=even.size()-1,m,z=0;
        while(l<=r){
            m=(l+r)>>1;
            int sum=b[even[m]]-b[even[i]-1];
            if(sum>k){
                r=m-1;
                z=even.size()-m;
            }
            else
                l=m+1;
        }
        ans+=z;
    }
    return min(ans,mx);
}


int32_t main(){
sp;
    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);
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
        int ans=solveit(a,k);
        cout<<ans<<"\n";
    }
    return 0;
}
