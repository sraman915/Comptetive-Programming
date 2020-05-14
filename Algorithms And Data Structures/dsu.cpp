#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define priority_queue pq
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 500005

int id[mxn], sz[mxn];

void init(int n){
    for(int i = 0; i <= n; ++i)
        id[i] = i, sz[i] = 1;
}

int root(int i){
    while(i != id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void unn(int p, int q){
    p = root(p);
    q = root(q);
    if(p == q)
        return;
    if(sz[p] < sz[q])
        swap(p, q);
    id[q] = p;
    sz[p] += sz[q];
    sz[q] = 0;
}


int32_t main(){
sp;

    return 0;
}
