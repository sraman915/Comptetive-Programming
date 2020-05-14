/*
SOLUTION BY RAMAN SHARMA
SCUBADIV - Scuba diver
https://www.spoj.com/problems/SCUBADIV/
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

int oo,ni,n;

struct node{
int x,y,w;
node(){
x=0,y=0,w=0;
}
node(int a,int b,int c){
x=a,y=b,w=c;
}
};

node p[1005];
int dp[1005][25][90];

int solve(int i,int x,int y){
if(x>=oo&&y>=ni)return 0;
if(i>=n)return inf;
if(x>oo)x=oo;
if(y>ni)y=ni;
auto &ans=dp[i][x][y];
if(ans!=-1)return ans;
ans=min(solve(i+1,x,y),solve(i+1,x+p[i].x,y+p[i].y)+p[i].w);
return ans;
}

int main(){
sp;
int t;
cin>>t;
while(t--){
    cin>>oo>>ni>>n;
    for(int i=0; i<n; ++i){
        int x,y,z;
        cin>>x>>y>>z;
        p[i]=node(x,y,z);
    }
    for(int i=0; i<=n; ++i)
        for(int j=0; j<25; ++j)
        for(int k=0; k<90; ++k)dp[i][j][k]=-1;
    cout<<solve(0,0,0)<<"\n";
}
return 0;}
