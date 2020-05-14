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

bool check(int x,vector<int> &a){
    int y=0;
    for(auto &it:a)
        if((it&x)==x)
            ++y;
    return (y>3);
}

int solveit(vector<int> &a){
    int n=a.size();
    int ans=0;
    for(int i=30; i>=0; --i){
        int temp=ans|(1<<i);
        if(check(temp,a))
            ans=temp;
    }
    return ans;
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
        assert(n>=4&&n<=100000);
        vector<int> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
            assert(a[i]>=1&&a[i]<=2000000000);
        }
        int ans=solveit(a);
        cout<<ans<<"\n";
    }
    return 0;
}
