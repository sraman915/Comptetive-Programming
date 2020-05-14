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

int bit[1004][1004];
int N = 1001;
int a[1005][1005];

void update(int x, int y, int val){
    int x1 = x, y1;
    while(x1 < N){
        y1 = y;
        while(y1 < N){
            bit[x1][y1] += val;
            y1 += (y1 & (-y1));
        }
        x1 += (x1 & (-x1));
    }
}

int read(int x, int y){
    int x1 = x, y1;
    int sum = 0;
    while(x1 > 0){
        y1 = y;
        while(y1 > 0){
            sum += bit[x1][y1];
            y1 -= (y1 & (-y1));
        }
        x1 -= (x1 & (-x1));
    }
    return sum;
}


int32_t main(){
sp;
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j){
            char ch;
            cin>>ch;
            if(ch == '*'){
                update(i, j, 1);
                a[i][j] = 1;
            }
        }
    int x1, y1, x2, y2;
    while(q--){
        int c;
        cin>>c;
        if(c == 2){
            cin>>x1>>y1>>x2>>y2;
            int ans=read(x2, y2) - read(x2, y1 - 1) - read(x1 - 1, y2) + read(x1 - 1, y1 - 1);
            cout<<ans<<"\n";
        }
        else{
            cin>>x1>>y1;
            if(a[x1][y1])
                update(x1, y1, -1);
            else
                update(x1, y1, 1);
            a[x1][y1] ^= 1;
        }
    }
    return 0;
}
