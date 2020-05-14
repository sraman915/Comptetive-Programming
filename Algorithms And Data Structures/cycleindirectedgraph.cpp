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
vector<int> q;
int vis[mxn];
int startt;

bool dfs(int x, int p){
    vis[x] = 1;
    for(auto &it: g[x]){
        if(vis[it]){
            q.push_back(it);
            startt = it;
            return true;
        }
        q.push_back(it);
        if(dfs(it, x))
            return true;
        q.pop_back();
    }
    return false;
}

int32_t main(){
sp;
    int n, m, x, y;
    cin>>n>>m;
    for(int i = 0; i < m; ++i){
        cin>>x>>y;
        g[x].push_back(y);
    }
    int ans=0;
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            q.clear();
            q.push_back(i);
            if(dfs(i, 0)){
                ans = 1;
                break;
            }
        }
    }
    if(ans){
        int i=0;
        while(i < q.size() && q[i] != startt)
            ++i;
        if(q.size()-i == 1){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        cout<<q.size() - i<<"\n";
        for(int j = i; j < q.size(); ++j)
            cout<<q[j]<<" ";
    }
    else
        cout<<"IMPOSSIBLE";

    return 0;
}
