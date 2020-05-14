/*
SOLUTION BY RAMAN SHARMA
https://www.spoj.com/problems/MCARDS/
MCARDS - Card Sorting

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

int lis(vector<int> &a){
int n=a.size();
int dp[n];
int mx=1;
for(int i=0; i<n; ++i)dp[i]=1;
for(int i=1; i<n; ++i){
    for(int j=0; j<i; ++j)
    if(a[i]>a[j]&&1+dp[j]>dp[i])dp[i]=1+dp[j];
 mx=max(mx,dp[i]);
}
return mx;
}

int main(){
sp;
int c,n,ans=inf;
cin>>c>>n;
int m=c*n;

int a[c];
for(int i=0; i<c; ++i)a[i]=i;
int color[m],b[m];
for(int i=0; i<m; ++i){
    cin>>color[i]>>b[i];
    --color[i];
    --b[i];
}
do{
    vector<int> v;
    int x=0;
    int start[c];
    for(int i=0; i<c; ++i)start[a[i]]=i;
        for(int i=0; i<m; ++i)v.pb(start[color[i]]*n+b[i]);
        int z=lis(v);
        ans=min(ans,m-z);
}while(next_permutation(a,a+c));
cout<<ans;
return 0;}
