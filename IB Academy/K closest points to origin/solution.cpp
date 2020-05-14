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

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
     priority_queue<pair<double,pair<int,int> > > q;
        int n=points.size();
        for(int i=0; i<n; ++i){
            double x=points[i][0];
            double y=points[i][1];
            q.push({x*x+y*y,{points[i][0],points[i][1]}});
            if(q.size()>K)q.pop();
        }
    vector<vector<int> > ans;
    while(!q.empty()){
        int x=q.top().second.first;
        int y=q.top().second.second;
        q.pop();
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        ans.push_back(v);
    }
    return ans;
    }

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    assert(n>=1&&n<=100000);
    vector<vector<int> > vv;
    for(int i=1; i<=n; ++i){
        int x,y;
        cin>>x>>y;
        assert(x>=-100000&&x<=100000);
        assert(y>=-100000&&y<=100000);
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        vv.push_back(v);
    }
    int k;
    cin>>k;
    assert(k>=1&&k<=n);
    vector<vector<int> > vvv=kClosest(vv,k);
    sort(vvv.begin(),vvv.end());
    for(int i=0; i<vvv.size(); ++i){
        cout<<"[";
        cout<<vvv[i][0]<<" "<<vvv[i][1]<<" ";
        cout<<"] ";
    }
    cout<<"\n";
}
return 0;}
