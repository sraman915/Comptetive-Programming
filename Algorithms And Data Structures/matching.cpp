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

int x1[mxn],x2[mxn],yy1[mxn],yy2[mxn];
int dp[mxn][22];
int n;

int value(int i,int j){
    return abs(x1[i]-x2[j])+abs(yy1[i]-yy2[j]);
}

int solve(int mask,int a){
    if(a==n)
        return 0;
    if(dp[mask][a]!=-1)
        return dp[mask][a];
    int w=INT_MAX;
    for(int i=0; i<n;++i){
        if(mask&(1<<i))
            continue;
        w=min(w,value(a,i)+solve(mask|(1<<i),a+1));
    }
    return (dp[mask][a]=w);
}

int32_t main(){
sp;
    cin>>n;
    for(int i=0; i<n;++i)
        cin>>x1[i]>>yy1[i];
    for(int i=0; i<n;++i)
        cin>>x2[i]>>yy2[i];
        memset(dp,-1,sizeof dp);
    cout<<solve(0,0);
    return 0;
}
