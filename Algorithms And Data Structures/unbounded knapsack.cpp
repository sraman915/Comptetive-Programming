#include<bits/stdc++.h>
using namespace std;

#define ll    long long
#define pb    push_back
const ll mod=1e9+7;
const int mxn=200005;
typedef pair<int,int> pi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,n;
    cin>>x>>n;
    int a[n+1],b[n+1],dp[x+1];
    memset(dp,0,sizeof dp);
    for(int i=1; i<=n;++i)cin>>a[i]>>b[i];
    for(int i=1; i<=x; ++i)
    for(int j=1; j<=n; ++j)
    if(a[j]<=i)
    dp[i]=max(dp[i],dp[i-a[j]]+b[j]);
    cout<<dp[x];

return 0;}
