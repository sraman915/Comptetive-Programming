/*
SOLUTION BY RAMAN SHARMA
IOIPALIN - Palindrome 2000
https://www.spoj.com/problems/IOIPALIN/

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
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
#define mxn 200005
string s;
int dp[5011][5011],n;

int solve(int i,int j){
if(i>j)return 0;
if(i<0)return 0;
if(j>=n)return 0;
if(dp[i][j]!=-1)return dp[i][j];
if(s[i]==s[j])dp[i][j]=solve(i+1,j-1);
else dp[i][j]=min(solve(i+1,j),solve(i,j-1))+1;
return dp[i][j];
}

int main(){
sp;
cin>>n;
cin>>s;
 for(int i=0; i<n; ++i)
    for(int j=0; j<n; ++j)
    dp[i][j]=-1;
cout<<solve(0,n-1)<<"\n";
return 0;}
