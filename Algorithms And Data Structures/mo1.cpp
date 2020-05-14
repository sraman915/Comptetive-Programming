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

int a[mxn], b[mxn], block = 741, n;
int ans[mxn], bit[mxn];
map<int,int> mp;

struct node{
    int l,r,id;
};

bool compare(const node &p, const node &q){
    int l = p.l / block;
    int r = q.l / block;
    if(l != r)
        return l < r;
    return((l & 1) ? p.r > q.r : q.r > p.r);
}

int read(int x){
    int sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= x & (-x);
    }
    return sum;
}

void update(int x, int val){
    while(x <= n){
        bit[x] += val;
        x += (x & (-x));
    }
}

int32_t main(){
sp;
    int qq;
    cin>>n>>qq;
    block = sqrt(n+n);
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        mp[a[i]];
    }
    int x = 0;
    for(auto &it:mp)
        it.second = ++x;
    for(int i = 1; i <= n; ++i)
        a[i] = mp[a[i]];
    node q[qq + 1];
    int l, r, id;
    for(int i = 1; i <= qq; ++i){
        cin>>q[i].l>>q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + qq + 1, compare);
    int curl = q[1].l, curr = curl - 1;
    int z = 0;
    for(int i = 1; i <= qq; ++i){
        l = q[i].l;
        r = q[i].r;
        id = q[i].id;
        while(curr < r){
            ++curr;
            z += read(n) - read(a[curr]);
            update(a[curr], 1);
        }
        while(curl > l){
            --curl;
            z += read(a[curl] - 1);
            update(a[curl], 1);
        }
        while(curl < l){
            z -= read(a[curl] - 1);
            update(a[curl], -1);
            ++curl;
        }
        while(curr > r){
            z -= read(n) - read(a[curr]);
            update(a[curr], -1);
            --curr;
        }
        ans[id] = z;
    }
    for(int i = 1; i <= qq; ++i)
        cout<<ans[i]<<"\n";
    return 0;
}
