/*
http://www.spoj.com/problems/NY10E/
NY10E - Non-Decreasing Digits
SOLUTION BY RAMAN SHARMA
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
ll dp[65][10],ans[65];

void pre(){
for(int i=1; i<65; ++i)
dp[i][0]=1LL;
for(int i=0; i<10; ++i)
    dp[1][i]=1;
ans[1]=10;
for(int i=2; i<65; ++i){
    ll temp=1LL;
    for(int j=1; j<10; ++j){
    dp[i][j]=dp[i][j-1]+dp[i-1][j];
    temp+=dp[i][j];
    }
    ans[i]=temp;
}
}

int main(){
sp;
pre();
int t,x,n;
cin>>t;
while(t--){
    cin>>x>>n;
    cout<<x<<" "<<ans[n]<<"\n";
}
return 0;}

