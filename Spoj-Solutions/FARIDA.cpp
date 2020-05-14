/*
SOLUTION BY RAMAN SHARMA
https://www.spoj.com/problems/FARIDA/
FARIDA - Princess Farida


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

int n;
ll a[mxn],dp[mxn];

ll solve(int i){
if(i>n)return 0;
auto &ans=dp[i];
if(ans!=-1)return ans;
ans=LLONG_MIN;
ans=max(ans,max(a[i]+solve(i+2),solve(i+1)));
return ans;
}

int main(){
sp;
int t;
cin>>t;
for(int _=1; _<=t; ++_){
    cout<<"Case "<<_<<": ";
    cin>>n;
    for(int i=0; i<=n; ++i)dp[i]=-1;
    for(int i=1; i<=n; ++i)cin>>a[i];
    cout<<solve(0)<<"\n";
}
return 0;}
