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

 int maxEnvelopes(vector<vector<int> >& A) {
    sort(A.begin(), A.end(), [](const vector<int> & p1, const vector<int> & p2){
        return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
    });
    vector<int>dp;
    for(auto x: A){
        int pos = lower_bound(dp.begin(), dp.end(), x[1]) - dp.begin();
        if(pos == dp.size()) dp.push_back(x[1]);
        else dp[pos] = x[1];
    }
    return dp.size();
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,tempn;
    cin>>n>>tempn;
    assert(n>=1&&n<=100000);
    assert(tempn==2);
    vector<vector<int> > A(n,vector<int>(2));
    for(int i=0; i<n; ++i){
        cin>>A[i][0]>>A[i][1];
    }
    int ans=maxEnvelopes(A);
    cout<<ans<<"\n";
}
return 0;}
