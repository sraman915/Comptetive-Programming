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

int tree[4*mxn], lazy[4*mxn];
int a[mxn];

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

void push(int i, int l, int r){
    if(!lazy[i])
        return;
    tree[i] += lazy[i];
    if(l != r){
        lazy[i + i] += lazy[i];
        lazy[i + i + 1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(int i, int l, int r, int x, int y){
    push(i, l, r);
    if(l == r){
        tree[i] = y;
        return;
    }
    int m = (l+r) >> 1;
    if(x <= m)
        update(i + i, l, m, x, y);
    else
        update(i + i + 1, m + 1, r, x, y);
    tree[i] = tree[i + i] + tree[i + i + 1];
}

void update1(int i, int l, int r, int x, int y, int val){
    push(i, l, r);
    if(l > r || x > r || l > y)
        return;
    if(l >= x && r <= y){
        lazy[i] += val;
        push(i, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update1(i + i, l, m, x, y, val);
    update1(i + i + 1, m + 1, r, x, y, val);
    tree[i] = tree[i + i] + tree[i + i + 1];
}

int query(int i, int l, int r, int x, int y){
    push(i, l, r);
    if(l > r || x > r || l > y)
        return 0;
    int m = (l + r) >> 1;
    if(l >= x && r <= y)
        return tree[i];
    return (query(i + i, l, m, x, y) + query(i + i + 1, m + 1, r, x, y));
}


int32_t main(){
sp;
    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    build(1, 1, n);
    while(q--){
        int c;
        cin>>c;
        if(c == 2){
            int l;
            cin>>l;
            cout<<query(1, 1, n, l, l)<<"\n";
        }
        else{
            int l, r, val;
            cin>>l>>r>>val;
            update1(1, 1, n, l, r, val);
        }
    }
    return 0;
}
