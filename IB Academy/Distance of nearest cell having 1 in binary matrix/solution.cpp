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

const int inf = 99999999;
int dir[][2]={{0,1},{1,0},{0,-1},{-1,0}};

vector<vector<int> > solveit(vector<vector<int> > A){
    int n=A.size();
    int m=A[0].size();
    queue<pair<int,int> > q;
    vector<vector<int> > distance(n,vector<int>(m,inf));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(A[i][j]==1){
                distance[i][j]=0;
                q.push({i,j});
            }
        }
    }
    assert(q.empty()==false);
    int x,y;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        int dx,dy;
        for(int k=0; k<4; ++k){
            dx=x+dir[k][0];
            dy=y+dir[k][1];
            if(dx>=0&&dx<n&&dy>=0&&dy<m&&distance[dx][dy]>distance[x][y]+1){
                distance[dx][dy]=distance[x][y]+1;
                q.push({dx,dy});
            }
        }
    }
    return distance;
}

void print(vector<vector<int> > &a){
    for(int i=0; i<a.size(); ++i){
        for(int j=0; j<a[i].size(); ++j){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,m;
cin>>n>>m;
assert(n>=1&&n<=500);
assert(m>=1&&m<=500);
vector<vector<int> > A(n,vector<int> (m));
int one=0;
for(int i=0; i<n; ++i)
for(int j=0; j<m; ++j){
cin>>A[i][j];
one+=A[i][j];
}
assert(one>0);
vector<vector<int> > ans=solveit(A);
for(auto &it:ans){
cout<<"[";
for(auto &it1:it)cout<<it1<<" ";
cout<<"] ";
}
cout<<"\n";
}
return 0;}
