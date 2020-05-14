/*
ABA12C- BUYING APPLES
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define inf 10000000
int unknapsc(int val[],int k){
int dp[k+1];
dp[0]=0;
for(int i=1; i<=k; ++i){
        dp[i]=inf;
    for(int j=1; j<=i; ++j){
            if(val[j]!=-1)
        dp[i]=min(dp[i],dp[i-j]+val[j]);

    }
    //for(int i=1; i<=k; ++i)
    //cout<<dp[i]<<" ";
//cout<<endl;
}

if(dp[k]==inf)
    return -1;
return dp[k];
}
int main(){
int t;
scanf("%d",&t);
while(t--){
    int n,k;
    scanf("%d%d",&n,&k);
    int val[k+1];
    val[0]=-1;
    for(int i=1; i<=k; ++i)
        scanf("%d",val+i);
    printf("%d\n",unknapsc(val,k));
}

return 0;}
