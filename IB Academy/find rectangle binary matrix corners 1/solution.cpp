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

int isRectangle(const vector<vector<int> >& matrix) {
    int rows = matrix.size();
    if (rows == 0)
        return 0;

    int columns = matrix[0].size();
    unordered_map<int, unordered_set<int> > table;

    for (int i = 0; i < rows; ++i) {
     for (int j = 0; j < columns - 1; ++j) {
        for (int k = j + 1; k < columns; ++k) {
          if (matrix[i][j] == 1 && matrix[i][k] == 1) {
            if (table.find(j) != table.end() && table[j].find(k) != table[j].end())
                        return 1;
            if (table.find(k) != table.end() && table[k].find(j) != table[k].end())
                        return 1;
            table[j].insert(k);
            table[k].insert(j);
          }
        }
      }
    }
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
assert(n>=1&&n<=200);
assert(m>=1&&m<=200);
vector<vector<int> > A(n,vector<int> (m));
for(int i=0; i<n; ++i){
for(int j=0; j<m; ++j){
cin>>A[i][j];
assert(A[i][j]>=0&&A[i][j]<=1);
}
}
int ans=isRectangle(A);
cout<<ans<<"\n";
}
return 0;}
