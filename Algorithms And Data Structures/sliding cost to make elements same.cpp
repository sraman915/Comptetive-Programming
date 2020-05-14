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

map<int,int> mp;
int revmap[mxn];
int m = 0;

pair<int,int> tree[4*mxn];

void update(int i, int l, int r, int x, int y){
    if(l == r){
        tree[i].first += y;
        tree[i].second += 1LL*revmap[x]*y;
        return;
    }
    int m = (l+r) >> 1;
    if(x <= m)
        update(i+i, l, m, x, y);
    else
        update(i+i+1, m+1, r, x, y);
    tree[i].first = tree[i+i].first + tree[i+i+1].first;
    tree[i].second = tree[i+i].second + tree[i+i+1].second;
}

int query1(int i, int l, int r, int k){
    if(l == r)
        return l;
    int m = (l+r) >> 1;
    if(tree[i+i].first >= k)
        return query1(i+i, l, m, k);
    return query1(i+i+1, m+1, r, k - tree[i+i].first);
}

pair<int,int> query(int i, int l, int r, int x, int y){
    if(l>r || x>r || l>y)
        return {0,0};
    if(l >= x && r <= y)
        return tree[i];
    int m = (l+r) >> 1;
    pair<int,int> p1 = query(i+i, l, m, x, y);
    pair<int,int> p2 = query(i+i+1, m+1, r, x, y);
    pair<int,int> p;
    p.first = p1.first + p2.first;
    p.second = p1.second + p2.second;
    return p;
}

int32_t main(){
sp;
    int n, k;
    cin>>n>>k;
    int a[n];
    for(auto &it:a){
        cin>>it;
        mp[it];
    }
    for(auto &it:mp)
        it.second = ++m;
    for(int i = 0; i < n; ++i){
        int index = mp[a[i]];
        revmap[index] = a[i];
        a[i] = index;
    }
    int b[3];
    b[1] = (k + 1) / 2;
    b[0] = (b[1] - 1 > 0? b[1] - 1 : b[1]);
    b[2] = (b[1] + 1 <= k? b[1] + 1 : b[1]);
    for(int i=0; i < k; ++i)
        update(1, 1, m, a[i], 1);
    int c[3];
    for(int i = k; i < n; ++i){
        c[0] = c[1] = c[2] = 0;
        int ans1 = LLONG_MAX;
        for(int j = 0; j < 3; ++j){
            int x = query1(1, 1, m, b[j]);
            pair<int,int> p1 = query(1, 1, m, 1, x);
            pair<int,int> p2 = query(1, 1, m, x, m);
            int sum = abs(1LL * revmap[x] * p1.first - p1.second) + abs(1LL * revmap[x] * p2.first - p2.second);
            //cout<<x<<" "<<b[j]<<" "<<revmap[x]<<" "<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<" \n";
            ans1 = min(ans1, sum);
        }
        cout<<ans1<<" ";
        update(1, 1, m, a[i-k], -1);
        update(1, 1, m, a[i], 1);
    }
    c[0] = c[1] = c[2] = 0;
    int ans1 = LLONG_MAX;
    for(int j = 0; j < 3; ++j){
        int x = query1(1, 1, m, b[j]);
        pair<int,int> p1 = query(1, 1, m, 1, x);
        pair<int,int> p2 = query(1, 1, m, x, m);
        int sum = abs(1LL * revmap[x] * p1.first - p1.second) + abs(1LL * revmap[x] * p2.first - p2.second);
        ans1 = min(ans1, sum);
    }
    cout<<ans1;
    return 0;
}
