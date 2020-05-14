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
#define mxn 1000005

int d[mxn];

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        for(int i = a; i < b+1; ++i)
            d[i - a] = 2;
        if(a == 1)
            d[0] = 1;
        for(int i = 2; 1LL * i * i <= b; ++i){
            for(int j = ((a - 1)/i + 1) * i; j <= b; j += i){
                if(j < i * i)
                    continue;
                if(j == i * i)
                    d[j - a] += 1;
                else
                    d[j - a] += 2;
            }
        }
    for(int i = a; i <= b; ++i){
        if(d[i - a] == 2)
            cout<<i<<"\n";
    }
    cout<<"\n";
    }
    return 0;
}
