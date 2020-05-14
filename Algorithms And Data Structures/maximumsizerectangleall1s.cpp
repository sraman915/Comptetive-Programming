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

int maxhistogramarea(vector<int> &a){
    int n = a.size();
    stack<int> s;
    int i = 0;
    int ans = 0;
    for(i = 0; i < n;){
        if(s.empty()||a[s.top()] <= a[i])
            s.push(i++);
        else{
            int y = s.top();
            s.pop();
            if(s.empty())
                ans = max(ans, a[y] * i);
            else
                ans=max(ans,a[y] * (i - 1 - s.top()));
        }
    }
    while(!s.empty()){
            int y = s.top();
            s.pop();
            if(s.empty())
                ans = max(ans, a[y] * i);
            else
                ans = max(ans,a[y] * (i - 1 - s.top()));
    }
    return ans;
}

int maximumrectangle(vector<vector<int> > &A){
    int n = A.size();
    int m = A[0].size();
    vector<int> col(m,0);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(A[i][j])
                ++col[j];
            else
                col[j] = 0;
        }
        ans = max(ans, maxhistogramarea(col));
    }
    return ans;
}

int32_t main(){
sp;
    int n;
    cin>>n;
    vector<vector<int> > a(n);
    for(auto &it:a)
        cin>>it;
    cout<<maxhistogramarea(a);
    return 0;2
}
