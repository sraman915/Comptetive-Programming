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

int tree[4*mxn], mx[4*mxn], a[mxn], n, k;

void build(int i, int l, int r){
    if(l == r){
        tree[i] = 1;
        mx[i] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(i + i, l, m);
    build(i + i + 1, m + 1, r);
    tree[i] = tree[i + i] + tree[i + i + 1];
    mx[i] = max(mx[i + i], mx[i + i + 1]);
}

int query(int i, int l, int r, int k){
    if(l == r)
        return mx[i];
    int m = (l + r) >> 1;
    if(tree[i + i] >= k)
        return query(i + i, l, m, k);
    return max(mx[i + i], query(i + i + 1, m + 1, r, k - tree[i + i]));
}

int p;

int getindex(int i, int l, int r, int x, int z = 0){
    if(l == r){
        p = l;
        return z;
    }
    int m = (l + r) >> 1;
    if(mx[i + i] >= x)
        return getindex(i + i, l, m, x, z);
    return getindex(i + i + 1, m + 1, r, x, z + tree[i + i]);
}
void update(int i, int l, int r, int x){
    if(l == r){
        tree[i] = 0;
        mx[i] = -1;
        return;
    }
    int m = (l + r) >> 1;
    if(x <= m)
        update(i + i, l, m, x);
    else
        update(i + i + 1, m + 1, r, x);
    tree[i] = tree[i + i] + tree[i + i + 1];
    mx[i] = max(mx[i + i], mx[i + i + 1]);
}


int32_t main(){
sp;
    cin>>n>>k;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    build(1, 1, n);
    vector<int> ans;
    for(int i = 1; i <= n; ++i){
        int ele = query(1, 1, n, k + 1);
        ans.push_back(ele);
        p = 0;
        int y = getindex(1, 1, n, ele);
        k -= y;
        update(1, 1, n, p);
    }
    for(auto &it: ans)
        cout<<it<<" ";
    return 0;
}
