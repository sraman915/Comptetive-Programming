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

int tree[4*mxn];
map<int,int> mp;
int b[mxn];

void update(int i, int l, int r, int x, int y){
    if(l == r){
        tree[i] += y;
        return;
    }
    int m = (l+r) >> 1;
    if(x <= m)
        update(i+i, l, m, x, y);
    else
        update(i+i+1, m+1, r, x, y);
    tree[i] = tree[i+i] + tree[i+i+1];
}

int query(int i, int l, int r, int k){
    if(l == r)
        return l;
    int m = (l+r) >> 1;
    if(tree[i+i] >= k)
        return query(i+i, l, m, k);
    return query(i+i+1, m+1, r, k - tree[i+i]);
}

int32_t main(){
sp;
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n;++i){
        cin>>a[i];
        mp[a[i]];
    }
    int index = 0;
    for(auto &it:mp)
        it.second = ++index;
    int m = index;
    for(int i = 0; i < n; ++i){
        int x = mp[a[i]];
        b[x] = a[i];
        a[i] = x;
    }
    for(int i = 0; i < k; ++i)
        update(1, 1, m, a[i], 1);
    int median = (k + 1) / 2;
    cout<<b[query(1, 1, m, median)]<<" ";
    for(int i = k; i < n; ++i){
        update(1, 1, m, a[i-k], -1);
        update(1, 1, m, a[i], 1);
        cout<<b[query(1, 1, m, median)]<<" ";
    }
    return 0;
}
