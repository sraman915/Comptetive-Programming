/*
SOLUTION BY RAMAN SHARMA
BEHAPPY - Be Awesome As Barney Stinson
https://www.spoj.com/problems/BEHAPPY/
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
#define mxn 500005

ll dp[25][101];
int m,n;
int a[25],b[25];

ll solve(int i,int n){
if(i>m)return (n==0);
if(n<0)return 0;
auto &ans=dp[i][n];
if(ans!=-1)return ans;
ans=0;
for(int j=a[i]; j<=b[i]; ++j)
    ans+=solve(i+1,n-j);
return ans;
}

int main(){
sp;
while(1){
    cin>>m>>n;
    if(m==0&&n==0)break;
    for(int i=0; i<=m; ++i)
        for(int j=0; j<=n; ++j)dp[i][j]=-1;
    for(int i=1; i<=m; ++i)cin>>a[i]>>b[i];
    cout<<solve(1,n)<<"\n";
}
return 0;}
