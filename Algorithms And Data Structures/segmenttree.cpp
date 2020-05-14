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

int tree[4*mxn], a[mxn];

void build(int i, int l, int r){
    if(l == r){
        tree[i] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(i + i, l, m);
    build(i + i + 1, m + 1, r);
    tree[i] = tree[i + i] + tree[i + i + 1];
}

void update(int i, int l, int r, int p, int val){
    if(l == r){
        tree[i] = val;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)
        update(i + i, l, m, p, val);
    else
        update(i + i + 1, m + 1, r, p, val);
    tree[i] = tree[i + i] + tree[i + i + 1];
}

int query(int i, int l, int r, int x, int y){
    if(l > r || x > r || l > y)
        return 0;
    if(l >= x && r <= y)
        return tree[i];
    int m = (l + r) >> 1;
    return (query(i + i, l, m, x, y) + query(i + i + 1, m + 1, r, x, y));
}


int32_t main(){
sp;
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    build(1, 1, n);
    int t, x, y;
    while(m--){
        cin>>t>>x>>y;
        if(t == 1)
            cout<<query(1, 1, n, x, y)<<"\n";
        else
            update(1, 1, n, x, y);
    }
    return 0;
}
