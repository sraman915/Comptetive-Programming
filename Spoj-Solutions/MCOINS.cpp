/*
MCOINS - Coins Game
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mxn 1000001
int dp[mxn],k,l;

void pre(){
dp[1]=1;
dp[k]=1;
dp[l]=1;
for(int i=2; i<mxn; ++i){
    if(dp[i-1]==0)
        dp[i]=1;
    else if(i-l>=0&&dp[i-l]==0)
    dp[i]=1;
    else if(i-k>=0&&dp[i-k]==0)
        dp[i]=1;
}
}

int main(){
sp;
int m,x;
cin>>k>>l>>m;
pre();
string s(m,'x');
for(int i=0; i<m; ++i){
    cin>>x;
    if(dp[x])
        s[i]='A';
    else s[i]='B';
}
cout<<s;
return 0;}
