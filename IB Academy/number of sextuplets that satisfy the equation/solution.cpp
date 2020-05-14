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
int a[105];
unordered_set<int> s;
unordered_map<int,int> m;

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    s.clear();
    for(int i=0; i<n; ++i){
        cin>>a[i];
        s.insert(a[i]);
    }
    assert(s.size()==n);
    int b[n*n*n+1];
int p=0;
m.clear();
for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
        for(int k=0; k<n; ++k){
            b[p++]=a[i]*a[j]+a[k];
            if(a[i]!=0){
            int temp=1LL*a[i]*(a[j]+a[k]);
            if(m.find(temp)==m.end())
                m[temp]=1;
            else
                m[temp]+=1;
        }}
    }
}
int ans=0;
for(int i=0; i<n*n*n; ++i){
    int temp=b[i];
    if(m.find(temp)!=m.end()){
        ans+=m[temp];
     ans=ans%mod;
    }
}
cout<<ans<<"\n";
}
return 0;}
