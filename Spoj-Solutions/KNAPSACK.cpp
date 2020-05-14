/*
KNAPSACK - The Knapsack Problem
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main(){
sp;
    int limit,n;
    cin>>limit>>n;
    int w[n],a[n];
    for(int i=0; i<n; ++i) cin>>w[i]>>a[i];
    int dp[n+1][limit+1];
    memset(dp,0,sizeof dp);
    for(int i=1;i<n+1; ++i){
        for(int j=1; j<limit+1; ++j){
            if(w[i-1]<=j)
        dp[i][j]=max(a[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
        else
            dp[i][j]=dp[i-1][j];
        }}
 cout<<dp[n][limit];
return 0;}
