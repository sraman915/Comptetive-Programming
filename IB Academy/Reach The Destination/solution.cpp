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

int solveit(int A){
    int ans=0;
    while(A%4==0){
        A/=4;
        ++ans;
    }
    while(A%5==0){
        A/=5;
        ++ans;
    }
    while(A%2==0){
        A/=2;
        ++ans;
    }
    while(A%3==0){
        A/=3;
        ++ans;
    }
    if(A==1)
        return ans;
    return -1;
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
        assert(n>=1&&n<=1000000000);
        int ans=solveit(n);
        cout<<ans<<"\n";
    }
    return 0;
}
