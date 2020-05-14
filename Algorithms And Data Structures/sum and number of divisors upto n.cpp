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

int numberofdivisors(int n){
    int y = sqrt(n);
    int x = 0;
    for(int i = 1; i <= y; ++i)
        x += n/i;
    return (x + x - (y * y));
}

int sumofdivisors(int n){
    int e, b, d = 2, sum = 0;
    do{
        e = n/(d - 1);
        b = n/d + 1;
        int x = e - b + 1;
        int y = b + e;
        if(x&1)
            y /= 2;
        else
            x /= 2;
        x = x % mod;
        y = y % mod;
        x = (1LL * x * y) % mod;
        x = (1LL * x * (d-1)) % mod;
        sum = (sum + x) % mod;
        d++;
    }while(b > d);

    for(int i = 1; i < b; i++)
        sum =(sum + 1LL* (n / i) * i) % mod;
    if (sum < 0)
        sum += mod;
    return sum;
}

int32_t main(){
sp;
    for(int i = 1; i <= 10; ++i)
        cout<<numberofdivisors(i)<<", ";
    cout<<"\n";
    for(int i = 1; i <= 10; ++i)
        cout<<sumofdivisors(i)<<", ";
    cout<<"\n";
    return 0;
}
