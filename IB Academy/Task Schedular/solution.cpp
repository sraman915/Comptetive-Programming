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

int minimumintervals(string A, int B) {
    unordered_map<char, int> record;
    int max_freq = 0;
    int max_tasks = 0;
    for(auto a : A) {
        record[a]++;
        max_freq = max(max_freq, record[a]);
    }
    for (auto task : record)
        if (task.second == max_freq)
            max_tasks++;
    int ans = (max_freq - 1) * (B+1) + max_tasks;
    return ans > A.size() ? ans : A.size();
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    string A;
    int B;
    cin>>A>>B;
    assert(A.size()>=1&&A.size()<=10000);
    assert(B>=0&&B<=100);
    int ans=minimumintervals(A,B);
    cout<<ans<<"\n";
}
return 0;}
