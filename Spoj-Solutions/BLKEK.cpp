/*
http://www.spoj.com/problems/BLKEK/
BLKEK - Emoticon
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
#define mxn 100005

void fun(string &b){
string a="KEK";
int n=b.size();
ll dp[3][n];
memset(dp,0,sizeof dp);
for(int i=0; i<3; ++i){
    for(int j=0; j<n; ++j){
          if(j)
            dp[i][j]=dp[i][j-1];
        if(!i){
            if(b[j]=='K')
            dp[i][j]+=1LL;
        }
        else{
        if(b[j]==a[i])
            dp[i][j]+=dp[i-1][j];
    }}
}
cout<<dp[2][n-1]<<"\n";
}

int main(){
sp;
int n;
cin>>n;
while(n--){
string b;
cin>>b;
fun(b);
}
return 0;}
