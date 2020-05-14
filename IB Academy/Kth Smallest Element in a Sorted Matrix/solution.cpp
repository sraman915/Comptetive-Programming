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

int KthSmallestInSortedMatrix(vector<vector<int>>& A, int B) {
    int n=A.size();
    int m=A[0].size();
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(q.size()<B)
                q.push(A[i][j]);
            else{
                if(A[i][j]<q.top()){
                    q.pop();
                    q.push(A[i][j]);
                }
            }
        }
    }
    return q.top();
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,m,k;
    cin>>n>>m;
    assert(n<=500&&m<=500);
    vector<vector<int> > A(n,vector<int> (m));
    int tot=n*m;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j){
            cin>>A[i][j];
            assert(A[i][j]>=1&&A[i][j]<=1000000000);
        }
    cin>>k;
    assert(k>=1&&k<=tot);
    int ans=KthSmallestInSortedMatrix(A,k);
    cout<<ans<<"\n";
}
return 0;}
