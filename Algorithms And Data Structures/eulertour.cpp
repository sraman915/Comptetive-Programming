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

vector<int> g[mxn];
int a[mxn], start[mxn], tme[mxn], finish[mxn];
int p = 0;
int tree[4 * mxn], lazy[4 * mxn];

void dfs(int x, int parent){
    start[x] = ++p;
    tme[p] = x;
    for(auto &it: g[x]){
        if(it != parent)
            dfs(it,x);
    }
    finish[x] = p;
}

void build(int i, int l, int r){
    if(l == r){
        tree[i] = a[tme[l]];
        return;
    }
    int m = (l + r) >> 1;
    build(i + i, l, m);
    build(i + i + 1, m + 1, r);
    tree[i] = tree[i + i] + tree[i + i + 1];
}

void update(int i, int l, int r, int x, int val){
    if(l == r){
        tree[i] = val;
        return;
    }
    int m = (l + r) >> 1;
    if(x >= l && x <= m)
        update(i + i, l, m, x, val);
    else
        update(i + i + 1, m + 1, r, x, val);
    tree[i] = tree[i + i] + tree[i + i + 1];
}

int query(int i, int l, int r, int x, int y){
    if(l > r || l > y || r < x)
        return 0;
    if(l >= x && r <= y)
        return tree[i];
    int m = (l + r) >> 1;
    return (query(i + i, l, m, x, y) + query(i + i + 1, m + 1, r, x, y));
}

int32_t main(){
sp;
    int n, m, x, y;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    for(int i = 1; i < n; ++i){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    build(1, 1, n);
    char c;
    while(m--){
        cin>>c;
        if(c == 'Q'){
            cin>>x;
            cout<<query(1, 1, n, start[x], finish[x])<<"\n";
        }
        else{
            cin>>x>>y;
            update(1, 1, n, start[x], y);
        }
    }
    return 0;
}
