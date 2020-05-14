/*
ACPC10D - Tri graphs
http://www.spoj.com/problems/ACPC10D/
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
#define mxn 1000005


int main(){
sp;
int j=0;
while(1){
    int n;
    cin>>n;
    if(!n) return 0;
    ll a[n+1][4],b[n+1][4];
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    for(int i=1; i<=n; ++i)for(int j=1; j<4; ++j)cin>>a[i][j];
    b[1][2]=a[1][2];
    b[2][1]=a[2][1]+a[1][2];
    b[2][2]=a[2][2]+min(b[1][2],min(b[2][1],a[1][2]+a[1][3]));
    b[2][3]=a[2][3]+min(b[2][2],min(a[1][2],a[1][2]+a[1][3]));
    for(int i=3; i<=n; ++i){
        b[i][1]=a[i][1]+min(b[i-1][1],b[i-1][2]);
        b[i][2]=a[i][2]+min(b[i][1],min(b[i-1][2],min(b[i-1][1],b[i-1][3])));
        b[i][3]=a[i][3]+min(b[i][2],min(b[i-1][2],b[i-1][3]));
    }
    ++j;
    cout<<j<<". "<<b[n][2]<<"\n";
}

return 0;}
