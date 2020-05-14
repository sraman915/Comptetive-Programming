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

int32_t main(){
sp;
    int n;
    cin>>n;
    int a[n+1], l[n+1], r[n+1];
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    for(int i = 1; i <= n; ++i){
        l[i] = 0;
        r[i] = n+1;
    }
    stack<int> s;
    for(int i = 1; i <= n; ++i){
        while(!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if(!s.empty())
            l[i] = s.top();
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    for(int i = n; i > 0; --i){//for maximum range
        while(!s.empty() && a[s.top()] < a[i])
            s.pop();
        if(!s.empty())
            r[i] = s.top();
        s.push(i);
    }

    for(int i = 1; i <= n; ++i){
        ++l[i];
        --r[i];
        cout<<a[i]<<" "<<l[i]<<" "<<r[i]<<"\n";
    }
    return 0;
}
