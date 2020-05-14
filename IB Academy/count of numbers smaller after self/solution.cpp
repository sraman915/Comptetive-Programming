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

int bit[mxn];
int mx=0;

int read(int x){
int sum=0;
while(x>0){
    sum+=bit[x];
    x-=(x&(-x));
}
return sum;
}

void update(int x,int y){
while(x<=mx){
    bit[x]+=y;
    x+=(x&(-x));
}
}


int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int a[n];
    mx=0;
    map<int,int> mp;
    for(int i=0; i<n; ++i){
        cin>>a[i];
        mp[a[i]];
    }
    int x=0;
    for(auto &it:mp)it.s=++x;
    mx=x;
    for(int i=0; i<=mx; ++i)bit[i]=0;
    for(auto &it:a)it=mp[it];
    int ans[n];
    memset(ans,0,sizeof ans);
    for(int i=n-1; i>=0; --i){
        ans[i]=read(a[i]-1);
        update(a[i],1);
    }
    for(int i=0; i<n; ++i)cout<<ans[i]<<" ";
    cout<<"\n";
}
return 0;}

