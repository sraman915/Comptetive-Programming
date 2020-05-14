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
//#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 500005

int dir[][2]={{0,1},{1,0},{-1,0},{0,-1}};
const int inf=99999999;

int solveit(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int distance[n][m];
        queue<pair<int,int> > q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1||grid[i][j]==0)
                    distance[i][j]=inf;
                 else {
                     distance[i][j]=0;
                     q.push({i,j});
                 }
            }
        }
        int x,y;

        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            int dx,dy;
            for(int k=0; k<4; ++k){
                dx=x+dir[k][0];
                dy=y+dir[k][1];
                if(dx>=0&&dx<n&&dy>=0&&dy<m&&grid[dx][dy]==1&&distance[x][y]+1<distance[dx][dy]){
                    distance[dx][dy]=1+distance[x][y];
                    q.push({dx,dy});
                }
            }

        }
        int ans=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1){
                    ans=max(ans,distance[i][j]);
                }
            }
        }
        return (ans==inf?-1:ans);
}

vector<vector<int> > A;

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m;
cin>>n>>m;
assert(n>=1&&n<=1000);
assert(m>=1&&m<=1000);
A.clear();
for(int i=0; i<n; ++i){
vector<int> v(m);
for(int j=0; j<m; ++j){
cin>>v[j];
assert(v[j]>=0&&v[j]<=2);
}
A.pb(v);
}
assert(A.size()==n);
assert(A[0].size()==m);
int ans=solveit(A);
cout<<ans<<"\n";
}
return 0;}
