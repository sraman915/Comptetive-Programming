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

vector<int> f(mxn, 2);

void factor(){
    f[1] = 1;
    for(int i = 2; i * i < mxn;++i)
            for(int j = i * i; j < mxn; j += i)
                if(j == i * i)
                    f[j] += 1;
                else
                    f[j] += 2;
}

int32_t main() {
sp;
    int t,k,x;
    cin>>t;
    factor();
    while(t--){
        cin>>k;
        cout<<f[k]<<"\n";
    }
    return 0;
}
