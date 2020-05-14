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

const int N = 300005;
vector<int> graph[N];
long long tree[4*N];
int start[N],finish[N],tme[N];
long long a[N],b[305];
int p;

int tc=0;


bool check(int n){
    for(int i=3; i*i<=n; i+=2)
        if(n%i==0)
            return 0;
    return 1;
}

void pre(){
    if(tc)
        return;
    tc=1;
    long long x=1LL;
    b[2]=1;
    for(int i=3; i<=300; i+=2){
        if(check(i)){
            b[i]=(1LL<<x);
            ++x;
        }
    }
}

void clean(int n){
    for(int i=0;i<=n; ++i){
        graph[i].clear();
        tree[i]=0;
        a[i]=0;
        start[i]=0;
        finish[i]=0;
        tme[i]=0;
    }
    p=0;
    for(int i=n+1; i<=4*n; ++i)
        tree[i]=0;
}

void dfs(int s,int parent){
    start[s]=++p;
    tme[p]=s;
    for(auto &i:graph[s]){
        if(i!=parent)
            dfs(i,s);
    }
    finish[s]=p;
}

void build(int i,int l,int r){
    if(l==r){
        tree[i]=a[tme[l]];
        return;
    }
    int m=(l+r)>>1;
    build(i+i,l,m);
    build(i+i+1,m+1,r);
    tree[i]=tree[i+i]|tree[i+i+1];
}

void update(int i,int l,int r,int x,long long val){
    if(l==r){
        tree[i]=val;
        return;
    }
    int m=(l+r)>>1;
    if(x>=l&&x<=m)
        update(i+i,l,m,x,val);
    else
        update(i+i+1,m+1,r,x,val);
    tree[i]=tree[i+i]|tree[i+i+1];
}

long long query(int i,int l,int r,int x,int y){
    if(l>r||l>y||r<x)
        return 0LL;
    if(l>=x&&r<=y)
        return tree[i];
    int m=(l+r)>>1;
    return (query(i+i,l,m,x,y)|query(i+i+1,m+1,r,x,y));
}

vector<int> solveit(int n,vector<int> &arr,vector<vector<int> > &edges,vector<vector<int> > &q){
    pre();
    clean(n);
    for(auto &it:edges){
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    for(int i=0; i<n; ++i)
        a[i+1]=b[arr[i]];
    vector<int> ans;
    dfs(1,0);
    build(1,1,n);
    for(int i=0; i<q.size(); ++i){
        int type=q[i][0];
        if(type==0){
            int index=start[q[i][1]];
            long long val=b[q[i][2]];
            update(1,1,n,index,val);
            ans.push_back(-1);
        }
        else{
            long long y=query(1,1,n,start[q[i][1]],finish[q[i][1]]);
            int val=(__builtin_popcountll(y));
            ans.push_back(val);
        }
    }
    return ans;
}

int32_t main(){
sp;
//freopen("input2.txt","r",stdin);
//freopen("output2.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=2&&n<=200000);
    vector<int> a(n);
    int tempn;
    cin>>tempn;
    assert(tempn==n);
    for(int i=0;i<n; ++i){
        cin>>a[i];
        assert(a[i]>=1&&a[i]<=300);
    }
    int m,tempm;
    cin>>m>>tempm;
    assert(tempm==2);
    assert(m==n-1);
    vector<vector<int> > edges(m,vector<int> (2));
    for(int i=0; i<m; ++i){
            cin>>edges[i][0]>>edges[i][1];
            assert(edges[i][0]>=1&&edges[i][0]<=n);
            assert(edges[i][1]>=1&&edges[i][1]<=n);
            assert(edges[i][1]!=edges[i][0]);
    }
    int q,tempq;
    cin>>q>>tempq;
    assert(q>=1&&q<=200000);
    assert(tempq==3);
    vector<vector<int> > query(q,vector<int> (3));
    for(int i=0; i<q; ++i){
        cin>>query[i][0]>>query[i][1]>>query[i][2];
        assert(query[i][0]>=0&&query[i][0]<=1);
        if(query[i][0]==0)
            assert(query[i][2]>=1&&query[i][2]<=300);
        assert(query[i][1]>=1&&query[i][1]<=n);
    }
    vector<int> ans=solveit(n,a,edges,query);
    for(auto &it:ans)
        cout<<it<<" ";
    cout<<"\n";
}
return 0;}
