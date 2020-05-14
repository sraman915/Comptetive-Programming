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

int a[23][23];
int n, x;
vector<int> v1[23][23], v2[23][23];

void karpaega(){
    for(int i = n-1, j = 0; j < n; --i, ++j){
        v1[i][j].clear();
        v2[i][j].clear();
    }
    int mask = (1<<(n-1));
    int sx = 0, sy = 0;
    for(int i = 0; i < mask; ++i){
        int pathsum = 0;
        sx = 0, sy = 0;
        for(int j = 0; j < n-1; ++j){
            pathsum += a[sx][sy];
            if(i & (1<<j))
                ++sx;
            else
                ++sy;
        }
        v1[sx][sy].push_back(pathsum);
    }

    for(int i = 0; i < mask; ++i){
        int pathsum = 0;
        sx = n-1, sy = n-1;
        for(int j = 0; j < n-1; ++j){
            pathsum += a[sx][sy];
            if(i & (1<<j))
                --sx;
            else
                --sy;
        }
        v2[sx][sy].push_back(pathsum);
    }
    int ans = 0;
    for(int i = n-1, j = 0; j < n; ++j, --i){
        sort(v1[i][j].begin(), v1[i][j].end());
        for(auto &it:v2[i][j])
            ans += (upper_bound(v1[i][j].begin(), v1[i][j].end(), x - (it + a[i][j]))) - v1[i][j].begin();
    }
    cout<<ans<<"\n";
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>x;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin>>a[i][j];
        if(n == 1){
            if(a[0][0] <= x)
                cout<<"1\n";
            else
                cout<<"0\n";
            continue;
        }
        karpaega();
    }
    return 0;
}
