/*
DSUBSEQ - Distinct Subsequences
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    int n=s.size();
    ll dp[n+1],last[256];
    dp[0]=1;
    memset(last,-1,sizeof(last));
    for(int i=1; i<=n; ++i){
        dp[i]=2LL*dp[i-1];
        if(dp[i]>=mod)
            dp[i]%=mod;
        if(last[s[i-1]]!=-1)
            dp[i]=(dp[i]-dp[last[s[i-1]]-1]);
        if(dp[i]<0)
            dp[i]+=mod;
        last[s[i-1]]=i;
    }
    cout<<dp[n]<<"\n";
}
return 0;
}
