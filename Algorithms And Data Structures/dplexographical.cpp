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
int g[4][2];
int dp[55][4];
int t,n;
int k;

int solve(int n,int x){
    if(n==0)
        return (x==t);
    auto &ans=dp[n][x];
    if(ans!=-1)
        return ans;
    ans=0;
    ans=solve(n-1,g[x][0])+solve(n-1,g[x][1]);
    return ans;
}


int32_t main(){
sp;
    g[0][0]=2;
    g[0][1]=1;
    g[1][0]=3;
    g[1][1]=0;
    g[2][0]=0;
    g[2][1]=3;
    g[3][0]=1;
    g[3][1]=2;
    char ch;
    cin>>ch>>n>>k;
    t=ch-'A';
    memset(dp,-1,sizeof dp);
    int z=solve(n,0);
    if(z<k){
        cout<<"impossible\n";
        return 0;
    }
    string ans;
    int curr=0;
    for(int i=1; i<=n; ++i){
        z=solve(n-i,g[curr][0]);
        if(z>=k){
            ans.pb('0');
            curr=g[curr][0];
        }
        else{
            ans.pb('1');
            curr=g[curr][1];
            k-=z;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
