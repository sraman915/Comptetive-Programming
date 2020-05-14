/*
SOLUTION BY RAMAN SHARMA
SQRBR - Square Brackets
https://www.spoj.com/problems/SQRBR/
*/
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

ll dp[50][50];
int a[50];
int n;

ll solve(int i,int s){
    if(s<0)return 0;
if(i>n+n)return s==0;
if(dp[i][s]!=-1)return dp[i][s];
ll w=0;
if(a[i])w=solve(i+1,s+1);
else w=solve(i+1,s+1)+solve(i+1,s-1);
return dp[i][s]=w;
}

int main(){
sp;
int t;
cin>>t;
while(t--){
    memset(dp,-1,sizeof dp);
    memset(a,0,sizeof a);
    int k,x;
    cin>>n>>k;
    for(int i=1; i<=k; ++i){
        cin>>x;
        a[x]=1;
    }
    cout<<solve(1,0)<<"\n";
}
return 0;}
