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

vector<int> d[mxn];
int p[mxn];

void sieve(){
    p[1] = p[0] = 1;
    for(int i = 4; i<mxn; i += 2)
        p[i] = 1;
    for(int i = 3; i * i < mxn; i += 2)
        if(p[i] == 0)
            for(int j = i * i; j < mxn; j += i + i)
                p[j] = 1;
}


void segsieve(int a, int b){
    for(int i = a; i <= b; ++i)
        d[i - a].clear();
    int limit = mxn;
    if(b < limit)
        limit = b;
    for(int i = 2 ; i < limit;  i++){
        if(p[i] == 0){
            for(int j = 1LL* (a + i - 1)/i * i ; j <= b ; j += i)
                d[j - a].push_back(i);
           }
    }
}

int calc(int a, int b){
    int ans = 0;
    for(int i = a; i <= b; ++i){
        int x = i;
        int num = 1;
        int mn = 99999;
        for(auto &it: d[i-a]){
            int z = 1;
            while(x % it == 0){
                ++z;
                x /= it;
            }
            num *= z;
            mn = min(mn, z);
        }
        if(x > 1){
            num *= 2;
            mn = min(mn, 2LL);
        }
        int temp = num - (num / mn) * (mn - 1);
        ans += temp;
    }
    return ans;
}

int32_t main(){
sp;
    sieve();
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        segsieve(a, b);
        cout<<calc(a, b)<<"\n";
    }
    return 0;
}
