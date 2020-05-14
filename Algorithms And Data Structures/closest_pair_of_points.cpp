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

int n;
int mindist;
pair<int, int> best_pair;

struct point {
    int x, y, id;
    point(){
        x = y = id = 0;
    }
    point(int x, int y, int id){
        this->x = x;
        this->y = y;
        this->id = id;
    }
};

struct compare_by_x {
    bool operator()(const point & a, const point & b) const {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

struct compare_by_y {
    bool operator()(const point & a, const point & b) const {
        return a.y < b.y;
    }
};

vector<point> a;
int x[mxn], y[mxn], toll[mxn], cmtoll[mxn], dis[mxn];

int tax(int i, int j){
    if( i > j )
        swap(i, j);
    return cmtoll[j] - cmtoll[i];
}

int distance(int i, int j){
    if(i > j)
        swap(i, j);
    return dis[j] - dis[i];
}

int distance_function(int i, int j){
    if(i == j)
        return (1LL<<55);
    if(i > j)
        swap(i, j);
    int d1 = distance(i, j);
    int d2 = tax(i, j);
    d1 *= d1;
    d2 *= d2;
    return d1 + d2;
}


void upd_ans(const point & a, const point & b) {
    int dist = distance_function(a.id, b.id);
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}

vector<point> t;

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, compare_by_y());
        return;
    }

    int m = (l + r) >> 1;
    int midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), compare_by_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}

int32_t main(){
sp;
    cin>>n;
    for(int i = 0; i < n; ++i)
        cin>>x[i];
    for(int i = 0; i < n; ++i)
        cin>>y[i];
    for(int i = 0; i < n; ++i)
        cin>>toll[i];
    if(n == 1){
        cout<<0;
        return 0;
    }
    for(int i = 1; i < n; ++i)
        cmtoll[i] = cmtoll[i-1] + toll[i];
    for(int i = 1; i < n; ++i){
        int term = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
        if(i & 1)
            term *= -1;
        dis[i] =  dis[i-1] + term;
    }
    for(int i = 0; i < n; ++i)
        a.push_back(point(cmtoll[i], dis[i], i));
    sort(a.begin(), a.end(), compare_by_x());
    t.resize(n);
    mindist = 1LL<<61;
    rec(0, n-1);
    cout<<mindist;
    return 0;
}
