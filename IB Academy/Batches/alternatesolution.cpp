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

const int N =100005;
int id[N],sz[N],sum[N];

void init(int A,vector<int> &strength){
    for(int i=1; i<=A;++i){
        id[i]=i;
        sz[i]=1;
        sum[i]=strength[i-1];
    }
}

int root(int i){
    while(i!=id[i]){
        id[i]=id[id[i]];
        i=id[i];
    }
    return i;
}

void unn(int p,int q){
    p=root(p);
    q=root(q);
    if(p==q)
        return;
    if(sz[p]<sz[q])
        swap(p,q);
    sz[p]+=sz[q];
    id[q]=p
    sz[q]=0;
    sum[p]+=sum[q];
}

int solve(int A,vector<int> &B,vector<vector<int> > &C,int D){
    init(A,B);
    for(auto &it:C)
        unn(it[0],it[1]);
    int ans=0;
    for(int i=1; i<=A; ++i){
        int x=root(i);
        if(x==i){
            if(sum[x]>=D)
                ++ans;
        }
    }
    return ans;
}


int32_t main(){
sp;
//freopen("input3.txt","r",stdin);
//freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){

}
return 0;}
