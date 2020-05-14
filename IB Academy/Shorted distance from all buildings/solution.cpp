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

const int dir[][2]={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inside(int x, int y,int n,int m) {
        return (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1);
}


int shortestDistance(vector<vector<int> > &A){
    int res=INT_MAX;
    int n=A.size();
    int m=A[0].size();
    int dist[n][m];
    int cnt[n][m];
    memset(cnt,0,sizeof cnt);
    memset(dist,0,sizeof dist);
    int visited[n][m];
    memset(visited,-1,sizeof visited);
    int buildingCnt=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(A[i][j]==1){
                ++buildingCnt;
                queue<pair<int,int> > q;
                q.push({i,j});
                visited[i][j]=buildingCnt;
                int level=1;
                while(!q.empty()){
                    int size=q.size();
                    for(int s=0; s<size; ++s){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int k=0; k<4; ++k){
                            int dx=x+dir[k][0];
                            int dy=y+dir[k][1];
                            if(inside(dx,dy,n,m)&&A[dx][dy]==0&&visited[dx][dy]!=buildingCnt){
                                dist[dx][dy]=dist[dx][dy]+level;
                                cnt[dx][dy]=cnt[dx][dy]+1;
                                visited[dx][dy]=buildingCnt;
                                q.push({dx,dy});
                            }

                        }

                    }
                    level=level+1;
                }
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(A[i][j]==0&&cnt[i][j]==buildingCnt){
                res=min(res,dist[i][j]);
                }
            }
        }
    return (res==INT_MAX?-1:res);
}


int32_t main(){
sp;
freopen("input2.txt","r",stdin);
freopen("output2.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m;
cin>>n>>m;
assert(n>=1&&n<=100);
assert(m>=1&&m<=100);
vector<vector<int> > a;
for(int i=0;i<n; ++i){
    vector<int> v(m);
    for(int j=0; j<m;++j)
    cin>>v[j];
    a.push_back(v);
}
int ans=shortestDistance(a);
cout<<ans<<"\n";
}
return 0;}
