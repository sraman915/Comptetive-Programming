/*
RPLB - Blueberries
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mxn 1010
int a[mxn],dp[mxn][mxn],n,k;

int rec(int i,int l){
if(i>n-1) return 0;
if(dp[i][l]!=-1)
    return dp[i][l];
int m=0,m1=0;
if (l+a[i]<=k)
    m=a[i]+rec(i+2,a[i]+l);
    m1=rec(i+1,l);
    return dp[i][l]=max(m,m1);
}

int main(){
sp;
int t;
cin>>t;
for(int i=1; i<t+1; ++i){
    cout<<"Scenario #"<<i<<": ";
    cin>>n>>k;
    for(int i=0; i<n; ++i) cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<rec(0,0)<<"\n";
}

return 0;}
