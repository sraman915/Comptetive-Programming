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
//#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 500005

void init(vector<int> &parent,vector<int> &size){
        for(int i=0; i<parent.size(); ++i){
            parent[i]=i;
            size[i]=1;
        }
}

int root(int x,vector<int> &parent){
        while(x!=parent[x]){
            parent[x]=parent[parent[x]];
            x=parent[x];
        }
        return x;
}

void union_by_weight(int x,int y,vector<int> &parent,vector<int> &size){
        x=root(x,parent);
        y=root(y,parent);
        if(x==y)
            return;
        if(size[x]>size[y])
            swap(x,y);
        size[y]+=size[x];
        size[x]=0;
        parent[x]=parent[y];
}

int solveit(vector<vector<int>>& stones) {
       int N=stones.size();
        if(N==0)
            return 0;
       vector<int> parent(20000);
       vector<int> size(20000);
       init(parent,size);
        for(auto &stone:stones){
            union_by_weight(stone[0],stone[1]+10000,parent,size);
        }
        unordered_set<int> s;
        for(auto &stone:stones){
            s.insert(root(stone[0],parent));
        }
        return N-s.size();
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,tempn;
cin>>n>>tempn;
assert(n>=1&&n<=100000);
assert(tempn==2);
vector<vector<int> > v(n);
map<pi,int> mp;
for(int i=0; i<n; ++i){
v[i].resize(2);
cin>>v[i][0]>>v[i][1];
assert(mp.find({v[i][0],v[i][1]})==mp.end());
mp[{v[i][0],v[i][1]}];
}
int ans=solveit(v);
cout<<ans<<"\n";
}
return 0;}
