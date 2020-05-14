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


int g[401][401];
int n;

void floyd(){
    for(int k = 0; k < n; ++k)
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int32_t main() {
sp;
    int m;
    cin>>n>>m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = 100000000;

    int x, y, w;
    while(m--){
        cin>>x>>y>>w;
        g[x-1][y-1] = w;
    }
    floyd();
    int q;
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<(g[x-1][y-1] == 100000000? -1 : g[x-1][y-1])<<"\n";


    }
    return 0;
}
