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
#define mxn 200005

int a[mxn], p[mxn];
const int block = 701;
int tot;
int d[5001][1002];
int n, k;

int query(int l, int r){
    int b1 = l/block;
    int x = 0;
    int i = l;
    while(i/block == b1 && i <= r){
        if(a[i] % k == p[b1])
            ++x;
        ++i;
    }
    ++b1;
    while(b1 < r/block){
        x += d[b1][p[b1]];
        ++b1;
    }
    i = b1 * block;
    while(i <= r){
        if(a[i] % k == p[b1])
            ++x;
        ++i;
    }
    return x;
}

void update(int l, int r, int y){
    y = y % k;
    if(y < 0)
        y += k;
    int b1 = l/block;
    int i = l;
    while(i/block == b1 && i <= r){
        int z = a[i];
        d[b1][z]--;
        z = (z + y) % k;
        d[b1][z]++;
        a[i] = z;
        ++i;
    }
    ++b1;
    while(b1 < r/block){
        int z = p[b1];
        p[b1] = (p[b1] - y + k) % k;
        ++b1;
    }
    i = b1 * block;
    while(i <= r){
        int z = a[i];
        d[b1][z]--;
        z = (z + y) % k;
        d[b1][z]++;
        a[i] = z;
        ++i;
    }
}

int32_t main(){
sp;
    int q, l, r, c, y;
    cin>>n>>q>>k;
    tot = (n + block - 1)/block;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
        a[i] %= k;
        ++d[i/block][a[i]];
    }

    while(q--){
        cin>>c;
        if(c == 2){
            cin>>l>>r;
            --l;
            --r;
            cout<<query(l, r)<<"\n";
        }
        else{
            cin>>l>>r>>y;
            --l;
            --r;
            update(l, r, y);
        }
    }
    return 0;
}
