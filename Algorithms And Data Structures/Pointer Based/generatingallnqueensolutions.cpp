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

vector<vector<vector<int> > > vv;

bool safe(int i,int j,vector<vector<int> > &v,int n){
if(v[i][j])return 0;
for(int k=i+1; k<n; ++k)
    if(v[k][j])return 0;
for(int k=j-1; k>-1;--k)
    if(v[i][k])return 0;
for(int k=i-1; k>-1; --k)
    if(v[k][j])return 0;
int k=j-1,p=i+1;
while(k>-1&&p<n)
if(v[p++][k--])return 0;
k=j-1,p=i-1;
while(k>-1&&p>-1)
    if(v[p--][k--])return 0;
return 1;
}

bool solve(vector<vector<int> > &v,int n,int x=0){
if(x==n){
    vv.push_back(v);
    return 1;
}
bool temp=0;
for(int i=0; i<n; ++i){
    if(safe(i,x,v,n)){
        v[i][x]=1;
        temp|=solve(v,n,x+1);
        v[i][x]=0;
    }
}
return temp;
}



int main(){
sp;
vector<vector<int> > v(4,vector<int>(4,0));
solve(v,4);
int n=vv.size();
for(int k=0; k<n; ++k){
    for(int i=0; i<4;++i){
        for(int j=0; j<4; ++j)
        cout<<vv[k][i][j]<<(j==3?"\n":" ");
    }
    nl;
}
return 0;}
