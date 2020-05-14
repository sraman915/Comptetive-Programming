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

int MatrixMultiplicationCost(vector<int> &A) {
    int n=A.size();
    int m[n][n];
    int i, j, k, L, q;
    for (i=1; i<n; i++)
        m[i][i] = 0;
    for (L=2; L<n; L++) {
        for (i=1; i<n-L+1; i++) {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + A[i-1]*A[k]*A[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    assert(m[1][n-1]<=INT_MAX&&m[1][n-1]>=0);
    return m[1][n-1];
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
assert(n>=2&&n<=100);
vector<int> a(n);
for(int i=0; i<n; ++i){
    cin>>a[i];
    assert(a[i]>=1&&a[i]<=100);
}
int ans=MatrixMultiplicationCost(a);
cout<<ans<<"\n";
}
return 0;}
