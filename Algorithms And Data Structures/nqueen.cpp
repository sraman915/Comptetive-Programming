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

int vis[8][8];
vector<string> a;

int n;

vector<vector<string> > ans;

bool check(int x,int y){
    if(vis[x][y])
        return 0;
    for(int i=y-1; i>=0; --i)
        if(vis[x][i])
            return 0;
    for(int i=x-1,j=y-1; i>=0&&j>=0;--j,--i)
        if(vis[i][j])
            return 0;
    for(int i=x+1,j=y-1; i<n&&j>=0; --j,++i)
        if(vis[i][j])
            return 0;
    return 1;
}

void solve(int y){
    if(y>=n){
        ans.push_back(a);
        return;
    }
    for(int i=0; i<n; ++i)
        if(check(i,y)){
            vis[i][y]=1;
            a[i][y]='1';
            solve(y+1);
            a[i][y]='0';
            vis[i][y]=0;
        }
}

int32_t main(){
sp;
    n=8;
    for(int i=0; i<n; ++i){
        string p=string(n,'0');
        a.push_back(p);
    }
    solve(0);
    for(auto &it:ans){
        vector<string> &v=it;
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j){
                cout<<v[i][j];
                if(j==n-1)
                    cout<<"\n";
            }
            cout<<"\n\n";
    }
    return 0;
}
