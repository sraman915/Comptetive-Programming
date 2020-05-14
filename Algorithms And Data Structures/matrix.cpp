#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

struct matrix{
    int a[2][2];
    matrix(){
        memset(a, 0, sizeof a);
    }
    matrix operator * (matrix b){
        matrix c = matrix();
        for (int i = 0; i < 2; ++i)
            for (int k = 0; k < 2; ++k)
                for (int j = 0; j < 2; ++j)
                    c.a[i][j] = (c.a[i][j] + (1LL * a[i][k] * b.a[k][j]) % mod) % mod;
        return c;
    }
};

matrix unit;


matrix modpow(matrix m, int n){
    if(n == 0)
        return unit;
    matrix half = modpow(m, n>>1);
    matrix out = half * half;
    if(n & 1)
        out = out * m;
  return out;
}

int32_t main(){
sp;
    unit = matrix();
    for(int i = 0; i < 2; ++i)
        unit.a[i][i] = 1LL;

return 0;}
