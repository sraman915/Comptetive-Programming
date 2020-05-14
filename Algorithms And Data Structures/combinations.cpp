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

int c[2005][2005];

void comb(){
    for(int i = 1; i < 2005; ++i){
        c[i][0] = c[i][i] = 1LL;
        c[i][1] = i;
        for(int j = 2; j < i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}

int32_t main(){
sp;
    int t;
    cin>>t;
    comb();
    while(t--){
        int x, y;
        cin>>x>>y;
        cout<<c[x][y]<<"\n";
    }
    return 0;
}
