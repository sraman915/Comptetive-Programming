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

vector<string> vv;

void rec(int x,int y,string &p,int i,int n){
if(i==n+n){
        if(x==n&&y==n)
    vv.push_back(p);
    return;
}
if(x<n){
        p[i]='(';
rec(x+1,y,p,i+1,n);
}
if(x>y){
    p[i]=')';
    rec(x,y+1,p,i+1,n);
}
}


int main(){
sp;
int n;
cin>>n;
string p=string(n+n,' ');
rec(0,0,p,0,n);
for(auto &it:vv)
    cout<<it<<"\n";
return 0;}
