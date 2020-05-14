/*
http://www.spoj.com/problems/MISERMAN/
MISERMAN - Wise And Miser
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

ll dp[101][101];

int main(){
sp;
int n,m;
cin>>n>>m;
for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
    cin>>dp[i][j];
for(int i=2; i<=n; ++i){
    for(int j=1; j<=m; ++j){
        ll temp=LLONG_MAX;
        if(j-1>0)
            temp=min(temp,dp[i-1][j-1]);
        temp=min(temp,dp[i-1][j]);
        if(j+1<=m)
            temp=min(temp,dp[i-1][j+1]);
        dp[i][j]+=temp;
    }
}
ll ans=LLONG_MAX;
for(int i=1; i<=m;++i)
    ans=min(ans,dp[n][i]);
cout<<ans;
return 0;}
