#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
//#define mod (long long)1000000007
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

const int N = 100005;
const int mod = 1000003;
int tree[4*N];
int a[N];

int xorr(int n){
    int y=n%4;
    if(y==0)
        return n%mod;
    if(y==1)
        return 1;
    if(y==2)
        return (n+1)%mod;
    return 0;
}

void build(int i,int l,int r){
    if(l==r){
        tree[i]=xorr(a[l]);
        return;
    }
    int m=(l+r)>>1;
    build(i+i,l,m),build(i+i+1,m+1,r);
    tree[i]=(tree[i+i]+tree[i+i+1])%mod;
}

void update(int i,int l,int r,int x,int y){
    if(l==r){
        tree[i]=xorr(y);
        return;
    }
    int m=(l+r)>>1;
    if(x<=m)
        update(i+i,l,m,x,y);
    else
        update(i+i+1,m+1,r,x,y);
    tree[i]=(tree[i+i]+tree[i+i+1])%mod;
}

int query(int i,int l,int r,int x,int y){
    if(l>r||x>r||l>y)
        return 0;
    if(l>=x&&r<=y)
        return tree[i];
    int m=(l+r)>>1;
    return (query(i+i,l,m,x,y)+query(i+i+1,m+1,r,x,y))%mod;
}

vector<int> solveit(vector<int> &A,vector<vector<int> > &B){
    for(int i=0; i<A.size(); ++i)
        a[i]=A[i];
    int n=A.size();
    for(int i=0; i<=4*n; ++i)
        tree[i]=0;
    build(1,0,n-1);
    vector<int> ans;
    for(auto &it:B){
        if(it[0]==1){
            ans.push_back(-1);
            update(1,0,n-1,it[1],it[2]);
        }
        else
            ans.push_back(query(1,0,n-1,it[1],it[2]));
    }
    return ans;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        assert(n>=1&&n<=100000);
        vector<int> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
            assert(a[i]>=1&&a[i]<=1000000000);
        }
        int m,tm;
        cin>>m>>tm;
        assert(m>=1&&m<=100000);
        assert(tm==3);
        vector<vector<int> > q(m,vector<int>(3));
        for(int i=0; i<m; ++i){
            cin>>q[i][0]>>q[i][1]>>q[i][2];
            assert(q[i][0]>=1&&q[i][0]<=2);
            if(q[i][0]==1){
                assert(q[i][1]>=0&&q[i][1]<n);
                assert(q[i][2]<=1000000000&&q[i][2]>=1);
            }
            else{
                assert(q[i][1]>=0&&q[i][1]<n);
                assert(q[i][2]>=0&&q[i][2]<n);
                assert(q[i][1]<=q[i][2]);
            }
        }
        vector<int> ans=solveit(a,q);
        for(auto &it:ans)
            cout<<it<<" ";
        cout<<"\n";
    }
    return 0;
}
