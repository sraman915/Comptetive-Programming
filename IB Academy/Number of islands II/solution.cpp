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


int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
int tc=0;

int visited[105][105];

bool check(int i,int j,int n,int m,vector<vector<int> > &A){
    return (i>=0 && i<n && j>=0 && j<m && (A[i][j]==1) && visited[i][j]!=tc);
}

void dfs(int i,int j,int n,int m,vector<vector<int> > &A){
    visited[i][j]=tc;
    int di,dj;
    for(int k=0; k<4; ++k){
        di=i+dir[k][0];
        dj=j+dir[k][1];
        if(check(di,dj,n,m,A))
            dfs(di,dj,n,m,A);
        }
}

int solve(vector<vector<int> > A){
    int n=A.size();
    int m=A[0].size();
    ++tc;
    int numberofislands=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
                if(A[i][j]==1 && visited[i][j]!=tc){
                    dfs(i,j,n,m,A);
                    ++numberofislands;
                }
            }
        }
    return numberofislands;
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
    assert(n>=1&&n<=100);
    assert(m>=1&&m<=100);
    vector<vector<int> > A(n,vector<int> (m));
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j){
            cin>>A[i][j];
            assert(A[i][j]>=0&&A[i][j]<=1);
            }
    int ans=solve(A);
    cout<<ans<<"\n";
}
return 0;}
