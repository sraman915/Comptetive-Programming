/*
MATSUM - Matrix Summation
http://www.spoj.com/problems/MATSUM/
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
#define mxn 1200
ll a[mxn+10][mxn+10],bit[mxn+10][mxn+10];

void init(){
for(int i=0; i<=mxn; ++i){
    for(int j=0; j<mxn; ++j){
        a[i][j]=0;
        bit[i][j]=0;
    }
}
}

void update(int x,int y,ll val){
int y1;
while(x<=mxn){
    y1=y;
    while(y1<=mxn){
        bit[x][y1]+=val;
        y1+=(y1&(-y1));
    }
    x+=(x&(-x));
}
}

ll get(int x,int y){
int y1;
ll s=0;
while(x>0){
    y1=y;
    while(y1>0){
        s+=bit[x][y1];
        y1-=(y1&(-y1));
    }
    x-=(x&(-x));
}
return s;
}

int main(){
sp;
int t;
cin>>t;
while(t--){
init();
int n;
cin>>n;
char b[5];
int x,y,x1,x2,y1,y2;
ll w;
while(1){
    cin>>b;
    if(b[1]=='N') break;
    if(b[1]=='E'){
            cin>>x>>y>>w;
        ll temp=a[x][y];
        update(x+1,y+1,w-temp);
    a[x][y]=w;
    }
    else{
        cin>>x1>>y1>>x2>>y2;
        ll ans=get(x2+1,y2+1)+get(x1,y1)-get(x2+1,y1)-get(x1,y2+1);
        cout<<ans<<"\n";
    }
}
cout<<"\n";
}
return 0;}
