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

vector<int> g[mxn];
int in[mxn];

int32_t main(){
sp;
    int n, m;
    cin>>n>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        ++in[y];
    }
    int c = 0;
    priority_queue<int,vector<int>, greater<int> > q;
    for(int i = 1;i < n+1; ++i)
        if(!in[i])
            q.push(i);

    vector<int> tpsort;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        tpsort.push_back(u);
        for(int &v:g[u]){
            if(in[v] != 0){
                --in[v];
                if(in[v] == 0)
                    q.push(v);
            }
        }
    }
    for(auto &it:tpsort)
        cout<<it<<" ";
    return 0;
}
