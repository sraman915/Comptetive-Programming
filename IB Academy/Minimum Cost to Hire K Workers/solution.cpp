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


static bool compare(const pair<double,int> &w1, const pair<double,int> &w2) {
        return w1.first < w2.first;
    }

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    priority_queue<int> quality_heap;
    vector<pair<double,int>> worker;
    for(int i=0; i< quality.size(); i++)
        worker.push_back(make_pair(double(wage[i])/quality[i],quality[i]));
    sort(worker.begin(),worker.end(), compare);
    double ratio = 0;
    int total_quality = 0;
    double min_cost = DBL_MAX;
    for(auto w: worker) {
        if(quality_heap.size() == K && w.second < quality_heap.top()) {
            total_quality -= quality_heap.top();
            quality_heap.pop();
        }
        if(quality_heap.size() < K) {
            quality_heap.push(w.second);
            total_quality+=w.second;
            ratio = w.first;
            if(quality_heap.size() == K)
                min_cost = min(ratio*total_quality, min_cost);
        }
    }
    assert(min_cost>=0&&min_cost<=2000000000.00);
    cout<<min_cost<<"\n";
    return min_cost;
}

int solveit(vector<int> &A,vector<int> &B,int C){
    double ans=mincostToHireWorkers(A,B,C);
    return ceil(ans);
}

int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n,tempn,k;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; ++i){
    cin>>a[i];
    assert(a[i]>=0&&a[i]<=1000);
    }
    cin>>tempn;
    assert(tempn==n);
    for(int i=0; i<n; ++i){
    cin>>b[i];
    assert(b[i]>=0&&b[i]<=1000);
    }
    cin>>k;
    assert(k>=1&&k<=n);
    int ans=solveit(a,b,k);
    cout<<ans<<"\n";
}
return 0;}
