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

int nnonfib(int n){
    int a = 1, b = 2, c = 3;
    while(n>0){
        a = b;
        b = c;
        c = a+b;
        n -= (c - b - 1);
    }
    n += (c - b - 1);
    return b + n;
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<nnonfib(n)<<"\n";
}
return 0;}
