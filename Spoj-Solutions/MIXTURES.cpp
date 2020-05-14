/*
SOLUTION BY RAMAN SHARMA
https://www.spoj.com/problems/MIXTURES/
MIXTURES - Mixtures

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
int n;
int a[105],p[105];
ll dp[105][105];

ll smoke(int i,int j,int k){
ll temp1=(p[k]-p[i-1])%100;
ll temp2=0;
if(j>=k)temp2=(p[j]-p[k])%100;
return temp1*temp2;
}

ll doit(int i,int j){
if(i>=j)return 0;
if(dp[i][j]!=-1)return dp[i][j];
dp[i][j]=INT_MAX;
for(int k=i; k<=j; ++k)
    dp[i][j]=min(dp[i][j],doit(i,k)+doit(k+1,j)+smoke(i,j,k));
return dp[i][j];
}

int main(){
sp;
while(cin>>n){
    for(int i=1; i<=n; ++i){
        cin>>a[i];
        p[i]=a[i];
        p[i]+=p[i-1];
    }
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=n; ++j)dp[i][j]=-1;
    cout<<doit(1,n)<<"\n";
}
return 0;}
