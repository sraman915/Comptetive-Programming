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
int n,m;
char a[505][505];
int dp[505][505];
int k;
int mx=(long long)(1e9);

void print(){
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cout<<dp[i][j]<<(j==m-1?"\n":" ");
}

int32_t main(){
sp;
    cin>>n>>m>>k;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin>>a[i][j];

    if(a[n-1][m-1]!='#')
        dp[n-1][m-1]=1;
    for(int i=n-2; i>=0; --i)
        if(a[i][m-1]=='.')
            dp[i][m-1]=dp[i+1][m-1];
    for(int i=m-2; i>=0; --i)
        if(a[n-1][i]=='.')
            dp[n-1][i]=dp[n-1][i+1];
    for(int i=n-2; i>=0; --i)
        for(int j=m-2; j>=0; --j)
            if(a[i][j]=='.')
                dp[i][j]=min(mx,dp[i+1][j]+dp[i][j+1]);
    int x=0,y=0;
    if(dp[0][0]<k){
        cout<<"impossible\n";
        return 0;
    }
    //print();
    string ans;
    int len=n+m-2;
    while(x+y<n+m-2){
        if(x+1<n&&a[x+1][y]=='.'&&dp[x+1][y]>=k){
            ans.pb('D');
            x=x+1;
        }
        else{
            ans.pb('R');
            if(x+1<n)
                k-=dp[x+1][y];
            y=y+1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
