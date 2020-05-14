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

int block=741;
int a[mxn];

inline int gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg+rotate)&3;
	const int rotateDelta[4]={3, 0, 0, 1};
	int nx=x&(x ^ hpow), ny = y & (y ^ hpow);
	int nrot=(rotate + rotateDelta[seg]) & 3;
	int subSquareSize = 1LL << (2*pow - 2);
	int ans = seg*subSquareSize;
	int add = gilbertOrder(nx, ny, pow-1, nrot);
	ans+=(seg==1||seg==2)?add:(subSquareSize-add-1);
	return ans;
}


struct node{
    int l,r,id;
    int ord;
    node(){}
    node(int x,int y,int z){
        l=x;
        r=y;
        id=z;
    }
    void calc(){
        ord=gilbertOrder(l,r,21,0);
    }
};

bool compare(const node &p,const node &q){
    return p.ord<q.ord;
}

int ans[mxn],c[mxn],curr=0;

void add(int x){
    if(c[x]==0)
        ++curr;
    ++c[x];
}

void del(int x){
    if(c[x]==1)
        --curr;
    --c[x];
}

int32_t main(){
sp;
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    for(int i=0; i<n; ++i){
        cin>>a[i];
        mp[a[i]];
    }
    int index=0;
    for(auto &it:mp)
        it.second=++index;
    for(int i=0; i<n; ++i)
        a[i]=mp[a[i]];
    node q[m];
    for(int i=0; i<m; ++i){
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        q[i]=node(x,y,i);
        q[i].calc();
    }
    sort(q,q+m,compare);
    int cl=q[0].l,cr=cl-1;
    for(int i=0; i<m; ++i){
        int r=q[i].r;
        int l=q[i].l;
        int id=q[i].id;
        while(cr<r)
            add(a[++cr]);
        while(cl>l)
            add(a[--cl]);
        while(cl<l)
            del(a[cl++]);
        while(cr>r)
            del(a[cr--]);
        ans[id]=curr;
    }
    for(int i=0; i<m; ++i)
        cout<<ans[i]<<"\n";
    return 0;
}
