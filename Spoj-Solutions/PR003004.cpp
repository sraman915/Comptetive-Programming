/*
SOLUTION BY RAMAN SHARMA
PR003004 - Digit Sum
http://www.spoj.com/problems/PR003004/
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


vector<int> digit(ll n){
vector<int> v;
while(n){
    v.push_back(n%10);
    n/=10;
}
return v;
}
ll dp[16][200][2];

ll solve(int id,ll sum,int y,vector<int> digit){
if(id<0)
    return sum;
if(dp[id][sum][y]!=-1)return dp[id][sum][y];
ll ways=0;
int k=y?digit[id]:9;
for(int i=0; i<=k; ++i){
    int ny=(digit[id]==i)?y:0;
    ways+=solve(id-1,sum+i,ny,digit);
}
dp[id][sum][y]=ways;
return ways;
}


int main(){
sp;
int t;
cin>>t;
while(t--){
    ll a,b;
    cin>>a>>b;
    if(a==-1&&b==-1)break;
    --a;
    memset(dp,-1,sizeof dp);
    ll x1=0,x2=0;
    if(a){
        vector<int> d=digit(a);
        x1=solve(d.size()-1,0,1,d);
    }
    memset(dp,-1,sizeof dp);
    vector<int> d=digit(b);
    x2=solve(d.size()-1,0,1,d);
    cout<<x2-x1<<"\n";
}
return 0;}
