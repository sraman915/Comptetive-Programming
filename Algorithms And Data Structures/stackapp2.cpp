#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<ll,ll>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

int a[mxn],l1[mxn],l2[mxn],r1[mxn],r2[mxn];
stack<int> s;
unordered_map<int,int> mp1,mp2;

int32_t main(){
sp;
    int n,q;
    cin>>n>>q;
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int x;
    for(int i=0; i<n; ++i){
        l1[i]=l2[i]=-1;
        r1[i]=r2[i]=n;
    }
    for(int i=0; i<n; ++i){//min
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(!s.empty())
            l1[i]=s.top();
        s.push(i);
    }
    while(!s.empty())
        s.pop();//min
    for(int i=n-1; i>-1; --i){
        while(!s.empty()&&a[s.top()]>a[i])
            s.pop();
        if(!s.empty())
            r1[i]=s.top();
        s.push(i);
    }

    while(!s.empty())
        s.pop();
    for(int i=0; i<n; ++i){
        while(!s.empty()&&a[s.top()]<=a[i])
            s.pop();
        if(!s.empty())
            l2[i]=s.top();
        s.push(i);
    }
    while(!s.empty())
        s.pop();
    for(int i=n-1; i>-1; --i){
        while(!s.empty()&&a[s.top()]<a[i])
            s.pop();
        if(!s.empty())
            r2[i]=s.top();
        s.push(i);
    }
    for(int i=0; i<n; ++i){
        int a1=i-l2[i]-1;
        int a2=r2[i]-i-1;
        int p=1LL*a1*a2+a1+a2+1;
        mp1[a[i]]+=p;
    }
    for(int i=0; i<n; ++i){
        int a1=i-l1[i]-1;
        int a2=r1[i]-i-1;
        int p=1LL*a1*a2+a1+a2+1;
        mp2[a[i]]+=p;
    }
    while(q--){
        cin>>x;
        if(mp1.count(x)==0)
            cout<<"0 0\n";
        else
            cout<<mp1[x]<<" "<<mp2[x]<<"\n";
    }
    return 0;
}
