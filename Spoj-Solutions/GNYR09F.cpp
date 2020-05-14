/*
SOLUTION BY RAMAN SHARMA
GNYR09F - Adjacent Bit Counts
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define priority_queue pq
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
ll dp[105][105][2];

void pre(){
dp[1][0][0]=1LL;
dp[1][0][1]=1LL;
for(int i=2; i<101; ++i){
    for(int j=0; j<i; ++j){
        dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][1];
        dp[i][j][1]=dp[i-1][j][0];
        if(j) dp[i][j][1]+=dp[i-1][j-1][1];
    }
}
}

int main(){
sp;
pre();
int t;
cin>>t;
while(t--){
    ll q,n,k;
    cin>>q>>n>>k;
    cout<<q<<" "<<dp[n][k][1]+dp[n][k][0]<<"\n";
}
return 0;}
