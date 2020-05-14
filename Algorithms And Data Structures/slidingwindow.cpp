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

vector<int>  maxofsubaaryofsizek(int *a, int n, int k){
    deque<int> q;
    vector<int> v;
    for(int i = 0; i < k; ++i){
        while(!q.empty() && a[i] >= a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for(int i = k; i < n; ++i){
        v.push_back(a[q.front()]);
        while(!q.empty() && q.front() <= i - k)
            q.pop_front();
        while(!q.empty() && a[i] >= a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    v.push_back(a[q.front()]);
    return v;
}


vector<int>  minofsubaaryofsizek(int *a,int n,int k){
    deque<int> q;
    vector<int> v;
    for(int i = 0; i < k; ++i){
        while(!q.empty() && a[i] <= a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for(int i = k; i < n; ++i){
        v.push_back(a[q.front()]);
        while(!q.empty()&&q.front() <= i - k)
            q.pop_front();
        while(!q.empty() && a[i] <= a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    v.push_back(a[q.front()]);
    return v;
}



int32_t main(){
sp;
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    vector<int> v1 = maxofsubaaryofsizek(a,n,k);
    vector<int> v2 = minofsubaaryofsizek(a,n,k);
    for(int i = 0; i < v1.size(); ++i)
        cout<<v1[i]<<" ";
    cout<<"\n";
    for(int i = 0; i < v2.size(); ++i)
        cout<<v2[i]<<" ";
    cout<<"\n";
    return 0;
}
