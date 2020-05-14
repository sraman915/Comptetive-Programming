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

struct point{
    double x, y;
    int index;
    point(){ }
    point(double a, double b, int i){
        x = a;
        y = b;
        index = i;
    };
    bool operator != (point &a){
        if(a.x != x || a.y != y)
            return true;
        return false;
    }
};


bool cmp(const point &a, const point &b){
    return a.y == b.y ? (a.x == b.x ? a.index < b.index : a.x < b.x) : a.y < b.y;
}
int orientation(point P, point Q, point R){           // <0 for anticlockwise, >0 for clockwise
    return (Q.x - P.x) * (R.y - P.y) - (R.x - P.x) * (Q.y - P.y);
}

double distance(point &a, point &b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void convex_hull(vector<point> &p ){
    if(p.size() == 1)
        return;
    sort(p.begin(), p.end(), cmp);
    vector<point> upper, lower;
    int k = 1;
    for(int i = 1 ; i < p.size() ; i++)
        if(p[i-1] != p[i])
            p[k++] = p[i];
    p.resize(k);
    int sz = 2*k;
    upper.resize(sz);
    lower.resize(sz);
    int j =0;
    k = 0;
    for(int i = 0; i < p.size(); i++){
        while(j >= 2 && orientation(lower[j-2], lower[j-1], p[i]) <= 0)
            j--;
        while(k >= 2 && orientation(upper[k-2], upper[k-1], p[i]) >= 0)
            k--;
        lower[j++] = p[i];
        upper[k++] = p[i];
    }
    lower.resize(j);
    upper.resize(k);
    for(int i = upper.size()-2 ; i > 0;i--)
        lower.push_back(upper[i]);
    p.clear();
    p = lower;
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        vector<point> p;
        double x, y, dist = 0.0;
        int n;
        cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>x>>y;
            p.push_back(point(x,y,i));
        }
        convex_hull(p);
        for(int i = 1; i < p.size(); ++i)
            dist += distance(p[i], p[i-1]);
        dist += distance(p[0], p.back());
        cout<<fixed<<setprecision(2)<<dist<<"\n";
        for(auto &it:p)
            cout<<it.index<<" ";
        cout<<"\n";
    }
    return 0;
}
