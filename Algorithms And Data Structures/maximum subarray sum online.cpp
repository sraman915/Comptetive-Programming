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



int a[mxn];
int INF = (1LL<<55);

struct node{
    int sum, pref, suff, ans;
    node(){
        sum = pref = suff = ans = -INF;
    }
};

node tree[4*mxn];

node combine(node a,node b){
    node x;
    if(a.ans ==-INF)
        return b;
    if(b.ans == -INF)
        return a;
    x.sum = a.sum + b.sum;
    x.pref = max(a.pref, a.sum + b.pref);
    x.suff = max(b.suff, b.sum + a.suff);
    x.ans = max(max(a.ans, b.ans), a.suff + b.pref);
    return x;
}

void build(int i, int l, int r){
    if(l == r){
        tree[i].sum = a[l];
        tree[i].ans = tree[i].pref = tree[i].suff = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(i + i, l, m);
    build(i + i + 1, m + 1, r);
    tree[i] = combine(tree[i + i], tree[i + i + 1]);
}

void update(int i, int l, int r, int pos, int val){
    if(l == r){
        tree[i].sum = val;
        tree[i].ans = tree[i].pref = tree[i].suff = val;
        return;
    }
    int m = (l + r) >> 1;
    if(pos <= m)
        update(i + i, l, m, pos, val);
    else
        update(i + i + 1, m + 1, r, pos, val);
    tree[i] = combine(tree[i + i], tree[i + i + 1]);
}

node query(int i, int l, int r, int x, int y){
    if(l > r || l > y || r < x)
        return node();
    if(l >= x && r <= y)
        return tree[i];
    int m = (l + r) >> 1;
    return combine(query(i + i, l, m, x, y), query(i + i + 1, m + 1, r, x, y));
}

int32_t main(){
sp;
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    build(1, 1, n);
    int x,y;
    while(q--){
        cin>>x>>y;
        update(1, 1, n, x, y);
        cout<<tree[1].ans<<"\n";
    }
    return 0;
}
