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

const int N =100005;
vector<int> graph[N];


void clean(int n){
    for(int i=0; i<=n; ++i)
        graph[i].clear();
}

void make_graph(int n,vector<vector<int> > &edges){
    clean(n);
    for(int i=0; i<edges.size();++i){
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}

bool isBipartite(int n) {
    if(!n)
        return true;
    int color[n];
    memset(color,-1,sizeof color);
    queue<int> q;
    for(int i=0; i<n; ++i){
        if(color[i]!=-1)
            continue;
        color[i]=1;
        q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto &it:graph[x]){
                if(color[it]==-1){
                    color[it]=color[x]^1;
                    q.push(it);
                }
                else if(color[it]==color[x])
                    return false;
                }
        }
    }
    return true;
}
int solve(int A,vector<vector<int> > &B){
    make_graph(A,B);
    if(isBipartite(A))
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
int n;
cin>>n;
assert(n>=1&&n<=100000);
int m,tempm;
cin>>m>>tempm;
assert(m>=1&&m<=200000);
assert(tempm==2);
vector<vector<int> > edges(m,vector<int>(2));
map<pair<int,int>,int> mp;
for(int i=0; i<m; ++i){
int x,y;
cin>>x>>y;
assert(x!=y);
assert(x>=0&&x<n);
assert(y>=0&&y<n);
edges[i][0]=x;
edges[i][1]=y;
if(x>y)swap(x,y);
assert(mp.find({x,y})==mp.end());
mp[{x,y}];
}
int ans=solve(n,edges);
cout<<ans<<"\n";
}
return 0;}
