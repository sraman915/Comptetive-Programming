/*
SOLUTION BY RAMAN SHARMA
http://www.spoj.com/problems/LUCIFER/
LUCIFER - LUCIFER Number
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

int p[101];

vector<int> digit(ll n){
vector<int> v;
while(n){
    v.push_back(n%10);
    n/=10;
}
return v;
}

void pre(){
p[0]=p[1]=1;
for(int i=2; i*i<=101; ++i){
    if(!p[i])
        for(int j=i*i; j<101; j+=i)p[j]=1;
}
}

ll dp[10][100][100][2];

ll solve(int id,ll sum1,ll sum2,int y,vector<int> digit){
if(id<0){
    if(sum1-sum2>0&&p[sum1-sum2]==0)return 1;
    return 0;
}
if(dp[id][sum1][sum2][y]!=-1)return dp[id][sum1][sum2][y];
ll ways=0;
int k=y?digit[id]:9;
for(int i=0; i<=k; ++i){
    int ny=(digit[id]==i)?y:0;
    int xo=0,xe=0;
    if(id&1)xe+=i;
    else xo+=i;
    ways+=solve(id-1,sum1+xe,sum2+xo,ny,digit);
}
if(!y)
dp[id][sum1][sum2][y]=ways;
return ways;
}


int main(){
sp;
int t;
cin>>t;
pre();
while(t--){
    ll a,b;
    cin>>a>>b;
    --a;
    memset(dp,-1,sizeof dp);
    ll x1=0,x2=0;
    if(a){
        vector<int> d=digit(a);
        x1=solve(d.size()-1,0,0,1,d);
    }
    memset(dp,-1,sizeof dp);
    vector<int> d=digit(b);
    x2=solve(d.size()-1,0,0,1,d);
    cout<<x2-x1<<"\n";
}
return 0;}
