/*
DIEHARD - DIE HARD
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
int dp[1005][1005];
int rec(int h,int ar){
if(h<1||ar<1)
    return -1;
     if(dp[h][ar]!=-1)
        return dp[h][ar];
    dp[h][ar]=(2+max(rec(h-2,ar-8),rec(h-17,ar+7)));
    return dp[h][ar];
}


int main(){
sp;
int t;
cin>>t;
memset(dp,-1,sizeof dp);
while(t--){
int h,ar;
cin>>h>>ar;
int ans;
if(dp[h][ar]!=-1)
    ans=dp[h][ar];
else
ans=rec(h,ar);
cout<<ans<<"\n";
}

return 0;}

