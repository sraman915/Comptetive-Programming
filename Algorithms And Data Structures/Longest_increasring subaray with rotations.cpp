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

int b[mxn];

//longest increasing subarray

struct node{
    int left, right, ans, leftmost, rightmost, len;
    node(){
        left = right = ans = leftmost = rightmost = len = 0;
    }
    node(int a1, int a2, int a4, int a3, int a5, int a6){
        left = a1;
        right = a2;
        len = a3;
        ans = a4;
        leftmost = a5;
        rightmost = a6;
    }
};

node tree[mxn];

void print(node a){
    cout<<a.len<<" "<<a.ans<<" "<<a.left<<" "<<a.right<<" "<<a.leftmost<<" "<<a.rightmost<<"\n";
}

node combine(node a, node b){
    if(a.ans == 0)
        return b;
    if(b.ans == 0)
        return a;
    node c;
    c.leftmost = a.leftmost;
    c.rightmost = b.rightmost;
    c.ans = max(a.ans, b.ans);
    c.left = a.left;
    c.right = b.right;
    c.len = a.len + b.len;
    if(a.rightmost < b.leftmost)
        c.ans = max(c.ans, b.left + a.right);
    if(c.left == a.len && a.rightmost < b.leftmost)
        c.left +=b.left;

    if(c.right == b.len && a.rightmost < b.leftmost)
        c.right += a.right;
    c.ans = max(c.ans, c.right);
    c.ans = max(c.ans, c.left);
    return c;
}

void build(int i, int l, int r){
    if(l == r){
        tree[i] = node(1, 1, 1, 1, b[l], b[l]);
        return;
    }
    int m = (l + r) >> 1;
    build(i + i, l, m);
    build(i + i + 1, m + 1, r);
    tree[i] = combine(tree[i + i], tree[i + i + 1]);
}

node query(int i, int l, int r, int x, int y){
    if(l > r || r < x || l > y)
        return node();
    if(l >= x && r <= y)
        return tree[i];
    int m = (l + r) >> 1;
    return combine(query(i + i, l, m, x, y), query(i + i + 1, m + 1, r, x, y));
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin>>a[i];
        for(int i = 0; i <= 4 * (n + n + n - 1); ++i)
            tree[i] = node();
        for(int i = 0; i < n + n + n; ++i)
            b[i] = a[i % n];
        int startx = n;
        int l = startx;
        int r = l + n - 1;
        build(1, 0, n + n + n - 1);
        char ch;
        while(q--){
            cin>>ch;
            if(ch == 'L'){
                --l;
                --r;
            }
            else{
                ++l;
                ++r;
            }
            if(l%n == 0){
                l = startx;
                r = l + n - 1;
            }
            node p = query(1, 0, n + n + n - 1, l, r);
            cout<<p.ans<<"\n";
        }
    }
    return 0;
}
