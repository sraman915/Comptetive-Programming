/*
PARTY - Party Schedule
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int main(){
sp;
while(1){
int n,b;
cin>>b>>n;
if(n==0&&b==0) return 0;
int a[n],w[n];
for(int i=0; i<n; ++i)
    cin>>w[i]>>a[i];
int dp[n+1][b+1];
for(int i=0; i<n+1; ++i){
    for(int j=0; j<b+1; ++j){
        if(i==0||j==0){
            dp[i][j]=0;
            continue;
        }
        if(w[i-1]<=j)
            dp[i][j]=max(a[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
        else
            dp[i][j]=dp[i-1][j];
    }
}
int ans=dp[n][b],wm;
for(int i=0; i<=b; ++i){
    if(dp[n][i]==ans){
        wm=i;
        break;
    }
}
cout<<wm<<" "<<ans<<"\n";
}
return 0;}
