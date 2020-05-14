#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
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

int p[22];
int a,b,x;

vector<int> dig(int n){
    vector<int> v;
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    return v;
}

int powersum(int n){
    int z=log10(n)+1;
    int i=0;
    int zz=0;
    while(n){
        zz=zz+p[i]*(n%10);
        n/=10;
        ++i;
    }
    return zz;
}

int dp[16][1<<18];

vector<int> digit;

int solve(int id,int z,int y){
    if(z<0)
        return 0;
    if(id<0){
        if(z>=0)
            return 1;
        return 0;
    }
    if(!y&&dp[id][z]!=-1)
        return dp[id][z];
    int ways=0;
    int k=y?digit[id]:9;
    for(int i=0; i<=k; ++i){
        int ny=(digit[id]==i)?y:0;
        int zz=z;
        zz-=p[id]*i;
        ways+=solve(id-1,zz,ny);
    }
    if(!y)
        dp[id][z]=ways;
    return ways;
}


int32_t main(){
sp;
    int t;
    cin>>t;
    p[0]=1;
    for(int i=1; i<22; ++i)
        p[i]=2LL*p[i-1];
    memset(dp,-1,sizeof dp);
    while(t--){
        cin>>a>>b;
        x=powersum(a);
    //cout<<x<<" ";
        int x1=0;
        digit.clear();
        digit=dig(b);
        x1=solve(digit.size()-1,x,1);
        cout<<x1<<"\n";
        digit.clear();
    }
    return 0;
}
