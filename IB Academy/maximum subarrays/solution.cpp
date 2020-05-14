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

vector<int> solve(vector<int> &A){
    int n=A.size();
    vector<int> B(n);
    long long l[n];
    long long r[n];
    for(int i=0; i<=n; ++i){
        l[i]=-1;
        r[i]=n;
    }
    stack<int> s;
    for(int i=0; i<n; ++i){
        while(!s.empty()&&A[s.top()]<=A[i])
            s.pop();
        if(!s.empty())
            l[i]=s.top();
        s.push(i);
    }

    while(!s.empty())s.pop();
    for(int i=n-1; i>-1; --i){
        while(!s.empty()&&A[s.top()]<A[i])
            s.pop();
        if(!s.empty())
            r[i]=s.top();
        s.push(i);
    }
    for(int i=0; i<n; ++i){
        long long a1=i-l[i]-1;
        long long a2=r[i]-i-1;
        long long p=((1LL*a1*a2)%mod+a1+a2+1)%mod;
        B[i]=p;
    }
return B;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
assert(n>=1&&n<=200000);
vector<int> A(n);
for(int i=0; i<n; ++i){
cin>>A[i];
assert(A[i]>0&&A[i]<=1000000000);
}
vector<int> ans=solve(A);
assert(ans.size()==n);
for(auto &it:ans)cout<<it<<" ";
cout<<"\n";
}

return 0;}

