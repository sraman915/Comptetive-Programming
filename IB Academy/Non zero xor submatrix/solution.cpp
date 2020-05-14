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

const int N = 100002;

vector<int> g[16];
int dp[N][16],ans[N];
int tc=0;

void make_edges(){
    vector<int> v;
    for(int i=0; i<=3; ++i)
        for(int j=0; j<=3; ++j)
            v.push_back(i^j);
    for(int i=0; i<v.size(); ++i)
        for(int j=0; j<v.size(); ++j){
            int x=(v[i]^v[j]);
            if(x)
                g[i].push_back(j);
        }
}

void preprocess(){
    for(int i=0; i<16; ++i)
            dp[0][i]=1LL;
        for(int i=1; i<N; ++i){
            for(int j=0; j<16; ++j){
                for(auto &it:g[j]){
                    dp[i][j]+=dp[i-1][it];
                    while(dp[i][j]>=mod)
                        dp[i][j]-=mod;
                    }
                ans[i]=(ans[i]+dp[i][j]);
                while(ans[i]>=mod)
                    ans[i]-=mod;
            }
        }
}

vector<int> solveit(vector<int> &A){
    if(tc==0){
        make_edges();
        preprocess();
    }
    tc=1;
    vector<int> res(A.begin(),A.end());
    for(auto &it:res)
        it=ans[it-1];
    return res;
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
        assert(n>1&&n<=100000);
        vector<int> A(n);
        for(int i=0; i<n; ++i){
            cin>>A[i];
            assert(A[i]>=2&&A[i]<=100000);
        }
        vector<int> res=solveit(A);
        for(auto &it:res)
            cout<<it<<" ";
        cout<<"\n";
    }
    return 0;
}
