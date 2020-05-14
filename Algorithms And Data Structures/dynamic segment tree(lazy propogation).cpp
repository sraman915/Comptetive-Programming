#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
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

int m;

struct node {
    int from, to;
    int value, lazy;
    node *left, *right;
    node() {
        from = 1;
        to = m;
        value = 0;
        lazy = 0;
        left = NULL;
        right = NULL;
    }
    void extend() {
        if(left == NULL) {
            left = new node();
            right = new node();
            left->from = from;
            left->to = (from + to) >> 1;
            right->from = ((from + to) >> 1) + 1;
            right->to = to;
        }
    }
};

node *root;

void update_tree(node *curr, int left, int right, int value) {
    if(curr->lazy) {
        curr->value += (curr->to - curr->from + 1) * curr->lazy;
        if(curr->from != curr->to) {
            curr->extend();
            curr->left->lazy += curr->lazy;
            curr->right->lazy += curr->lazy;
        }
        curr->lazy = 0;
    }
    if((curr->from) > (curr->to) || (curr->from) > right || (curr->to) < left)
        return;
    if(curr->from >= left && curr->to <= right) {
        curr->value += (curr->to-curr->from + 1) * value;
        if(curr->from != curr->to) {
            curr->extend();
            curr->left->lazy += value;
            curr->right->lazy += value;
        }
        return;
    }
    curr->extend();
    update_tree(curr->left, left, right, value);
    update_tree(curr->right, left, right, value);
    curr->value = curr->left->value + curr->right->value;
}

int query_tree(node *curr, int left, int right) {
    if((curr->from) > (curr->to) || (curr->from) > right || (curr->to) < left)
        return 0;
    if(curr->lazy) {
        curr->value += (curr->to-curr->from+1)*curr->lazy;
        curr->extend();
        curr->left->lazy += curr->lazy;
        curr->right->lazy += curr->lazy;
        curr->lazy = 0;
    }
    if(curr->from >= left && curr->to <= right)
        return curr->value;
    int q1,q2;
    curr->extend();
    q1 = query_tree(curr->left, left, right);
    q2 = query_tree(curr->right, left, right);
    return q1 + q2;
}

int32_t main(){
sp;
    int q;
    int m1, m2;
    int a, b, x, y;
    cin>>q>>m1>>m2;
    m = m1;
    unordered_map<int,int> mp;
    int prev = 0;
    root = new node();
    while(q--){
        int c;
        cin>>c;
        if(c == 1){
            cin>>a>>b;
            x = (prev + a) % m1 + 1;
            y = (prev + b) % m2 + 1;
            if(mp.find(x) != mp.end()){
                int z = mp[x];
                mp[x] = y;
                y -= z;
            }
            else
                mp[x] = y;
            update_tree(root, x, x, y);
        }
        else{
            cin>>a;
            x = (prev + a) % m1 + 1;
            int ans = query_tree(root, 0, x);
            cout<<ans<<"\n";
            prev = ans;
        }
    }
    return 0;
}
