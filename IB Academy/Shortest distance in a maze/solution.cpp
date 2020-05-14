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

struct Grid {
    int x, y;
    int d;

    Grid(int _x = 0, int _y = 0, int _d = 0): x(_x), y(_y), d(_d) {};

    bool operator < (const Grid &g) const {
        return d > g.d;
    }
};

 int findMinimumDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        auto &a = maze;
        int n = a.size();
        int m = a[0].size();

        int sx = start[0];
        int sy = start[1];
        int ex = destination[0];
        int ey = destination[1];

        vector<vector<int>> v(n, vector<int>(m, INT_MAX));
        priority_queue<Grid> pq;
        int i;
        int d, d1;
        int x, y;
        int x1, y1;
        int x2, y2;

        pq.push(Grid(sx, sy, 0));
        while (!pq.empty() && v[ex][ey] == INT_MAX) {
            x = pq.top().x;
            y = pq.top().y;
            d = pq.top().d;
            pq.pop();
            if (v[x][y] != INT_MAX) {
                continue;
            } else {
                v[x][y] = d;
            }

            for (i = 0; i < 4; ++i) {
                x1 = x;
                y1 = y;
                d1 = 0;
                while (true) {
                    x2 = x1 + dir[i][0];
                    y2 = y1 + dir[i][1];
                    if (inside(x2, y2,n,m) && a[x2][y2] == 0) {
                        x1 = x2;
                        y1 = y2;
                        ++d1;
                    } else {
                        break;
                    }
                }
                if (d1 > 0 && v[x1][y1] == INT_MAX) {
                    pq.push(Grid(x1, y1, d + d1));
                }
            }
        }
        while (!pq.empty()) {
            pq.pop();
        }
        int res = (v[ex][ey] != INT_MAX ? v[ex][ey] : -1);
        v.clear();

        return res;
    }

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,m,tempn;
    cin>>n>>m;
    assert(n>=1&&n<=1000);
    assert(m>=1&&m<=1000);
    vector<vector<int> > a;
    vector<int> b(2);
    vector<int> c(2);
    for(int i=0;i<n; ++i){
        vector<int> v(m);
        for(int j=0; j<m; ++j){
            cin>>v[j];
            }
        a.push_back(v);
        }
    cin>>tempn;
    assert(tempn==2);
    cin>>b[0]>>b[1];
    assert(b[0]>=0&&b[0]<n);
    assert(b[1]>=0&&b[1]<m);
    cin>>tempn;
    assert(tempn==2);
    cin>>c[0]>>c[1];
    assert(c[0]>=0&&c[0]<n);
    assert(c[1]>=0&&c[1]<m);
    assert(b!=c);
    int ans=findMinimumDistance(a,b,c);
    cout<<ans<<"\n";
}
return 0;}
