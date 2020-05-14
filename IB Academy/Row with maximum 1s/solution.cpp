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

int solveit(vector<vector<int> > &a){
    int n=a.size();
    int ans=0;
    int row =0,i,j;
    for (i=0,j=n-1; i<n&&j>0;i++){
        while (a[i][j]==1&&j>=0){
            row = i;
            j--;
        }
    }
    return row;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        assert(n>=1&&n<=500);
        assert(n==m);
        vector<vector<int> > a(n,vector<int> (n));
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j){
                cin>>a[i][j];
                assert(a[i][j]>=0&&a[i][j]<=1);
        }
        int ans=solveit(a);
        cout<<ans<<"\n";
    }
    return 0;
}
