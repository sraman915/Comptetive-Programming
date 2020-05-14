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

double a1, a2, b1, b2, c1, c2;

double dis(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double d1(double x){
    double y1 = ((x - a1) * (x - a1))/b1 - c1/b1;
    double y2 = ((x - a2) * (x - a2))/b2 - c2/b2;
    return abs(y1 - y2);
}


void solve(){
    double mid1, st = -1e12, en = 1e12, mid2;
    double x1, x2, y1, y2;
    double ans = 2e18;
    for(int i = 0; i < 400; ++i){
        mid1 = st + (en - st)/3.0;
        mid2 = en - (en - st)/3.0;
        double m1 = d1(mid1);
        double m2 = d1(mid2);
        ans = min(ans, m1);
        ans = min(ans, m2);
        if(m1 < m2)
            en = mid2;
        else
            st = mid1;
    }
    cout<<fixed<<setprecision(8)<<ans<<"\n";
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        cin>>a1>>b1>>c1>>a2>>b2>>c2;
        solve();
    }
    return 0;
}
