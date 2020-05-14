#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
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


struct node{
    public:
    int st,en,prof;
    node(){
        st=0,en=0,prof=0;
    }
};

bool comp(const node &a,const node &b){
    return (a.en<b.en);
}

int32_t main(){
sp;
    int n;
    cin>>n;
    node c[n];
    for(int i=0; i<n; ++i)
        cin>>c[i].st>>c[i].en>>c[i].prof;
    int dp[n+1];
    sort(c,c+n,comp);
    memset(dp,0,sizeof dp);
    dp[0]=c[0].prof;
    for(int i=1; i<n; ++i){
        int y=c[i].prof;
        int l=0,r=i-1,m,z=-1;
        while(l<=r){
                m=(l+r)>>1;
            if(c[m].en<c[i].st){
                z=m;
                l=m+1;
            }
            else
                r=m-1;
        }
        if(z!=-1)
            y+=dp[z];
        dp[i]=max(dp[i-1],y);
    }
    cout<<dp[n-1];
    return 0;
}
