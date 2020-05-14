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

vector<int> nextgreaterfrequencyelement(vector<int> &a){
    int n = a.size();
    vector<int> ans(n, -1);
    stack<int> s;
    unordered_map<int,int> freq;
    for(auto &it: a)
        ++freq[it];
    for(int i = 0; i < n; ++i){
        while(!s.empty() && freq[a[s.top()]] < freq[a[i]]){
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int32_t main(){
sp;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    vector<int> ans1 = nextgreaterfrequencyelement(a);
    for(auto &it: ans1)
        cout<<it<<" ";
    cout<<"\n";
    return 0;
}
