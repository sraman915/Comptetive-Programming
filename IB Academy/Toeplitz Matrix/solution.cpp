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

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    if(n<=1||m<=1)
        return true;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(i+1<n&&j+1<m){
                if(matrix[i+1][j+1]!=matrix[i][j])
                    return false;
            }
        }
    }
    return true;
}

int solve(vector<vector<int>> &A){
    int n=A.size();
    int m=A[0].size();
    assert(n>=1&&n<=500);
    assert(m>=1&&m<=500);
    if(isToeplitzMatrix(A))
        return 1;
    return 0;
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
vector<vector<int> > A(n,vector<int>(m));
for(int i=0; i<n; ++i)
for(int j=0; j<m; ++j)
cin>>A[i][j];
cout<<solve(A)<<"\n";
}
return 0;}
