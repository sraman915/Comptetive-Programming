/*
RENT - Rent your airplane and make money
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long

struct node{
    public:
int st,en,prof;
    node(){
    st=0,en=0,prof=0;}
};
bool comp(node a,node b){
return (a.en<b.en);
}
int main(){
 sp;
 int t;
 cin>>t;
 while(t--){
        int n;
 cin>>n;
    node c[n];
    for(int i=0; i<n; ++i) cin>>c[i].st>>c[i].en>>c[i].prof;
    for(int i=0; i<n; ++i)
        c[i].en=c[i].st+c[i].en;
    int dp[n+1];
    sort(c,c+n,comp);
  /*  for(int i=0; i<n; ++i)
        cout<<c[i].st<<" "<<c[i].en<<" "<<c[i].prof<<"\n";*/
    memset(dp,0,sizeof dp);
    dp[0]=c[0].prof;
    for(int i=1; i<n; ++i){
        int y=c[i].prof;
        int l=0,r=i-1,m,z=-1;
        while(l<=r){
                m=(l+r)>>1;
            if(c[m].en<c[i].st){
             if(c[m+1].en<c[i].st)
                l=m+1;
             else {
                z=m;
                break;
             }
            }
            else r=m-1;
        }
        if(z!=-1)
            y+=dp[z];
        dp[i]=max(dp[i-1],y);
    }
    cout<<dp[n-1]<<"\n";
 }
return 0;}
