/*
STAR3CAS - THE WEIRD STAIRCASE
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 100000000
#define mod 1000000007
#define mxn 22
#define pi pair<int,int>
int n,a[22],d[22];
int bfs(){
d[0]=0;
queue<int> q;
q.push(0);
int x,y,z;
while(!q.empty()){
    x=q.front();
    q.pop();
    z=x+a[x];
    y=x+1;
    if(z>-1&&z<n+1){
        if(d[z]>d[x]+1){
            d[z]=d[x]+1;
        if(z!=n)
            q.push(z);
    }}
    if(y<n+1){
        if(d[y]>d[x]+1){
            d[y]=d[x]+1;
            if(y!=n)
                q.push(y);
        }
    }
}
if(d[n]==inf) return -1;
return d[n];
}



int main(){
sp;
int t;
cin>>t;
while(t--){
       for(int i=0; i<22; ++i)
        d[i]=inf;
    cin>>n;
    memset(a,0,sizeof a);
    for(int i=0; i<n; ++i) cin>>a[i];
    cout<<bfs()<<"\n";

}
return 0;}
