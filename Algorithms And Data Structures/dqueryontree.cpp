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

int block = 741;
int a[mxn];
vector<int> g[mxn];
int start[mxn], finish[mxn], att[mxn], p = 0;

void dfs(int x,int parent){
    start[x] = ++p;
    att[p] = a[x];
    for(auto &it: g[x])
        if(it != parent)
            dfs(it, x);
    finish[x] = p;
}

struct node{
    int l, r, id;
    node(){}
    node(int l, int r, int id){
        this->l = l;
        this->r = r;
        this->id = id;
    }
};

bool compare(const node &p, const node &q){
    int b1 = p.l/block;
    int b2 = q.l/block;
    if(b1 != b2)
        return b1 < b2;
    return ((b1 & 1) ? p.r > q.r : p.r < q.r);
}

int ans[mxn], c[mxn], curr = 0;

void add(int x){
    if(c[x] == 0)
        ++curr;
    ++c[x];
}

void del(int x){
    if(c[x] == 1)
        --curr;
    --c[x];
}

int32_t main(){
sp;
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        mp[a[i]];
    }
    int index = 0;
    for(auto &it: mp)
        it.second = ++index;
    for(int i = 1; i <= n; ++i)
        a[i] = mp[a[i]];

    int m = n;
    for(int i = 1; i < n; ++i){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    node q[m];
    for(int i = 0; i < m; ++i)
        q[i] = node(start[i + 1], finish[i + 1], i);
    sort(q, q + m, compare);
    int cl = q[0].l, cr = cl - 1;
    for(int i = 0; i < m; ++i){
        int r = q[i].r;
        int l = q[i].l;
        int id = q[i].id;
        while(cr < r)
            add(att[++cr]);
        while(cl > l)
            add(att[--cl]);
        while(cl < l)
            del(att[cl++]);
        while(cr > r)
            del(att[cr--]);
        ans[id] = curr;
    }
    for(int i = 0; i < m; ++i)
        cout<<ans[i]<<" ";
    return 0;
}
