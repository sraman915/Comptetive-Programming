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


mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
random_device rd;

uniform_real_distribution<double> r1(1.0,20.0);
uniform_int_distribution<int> r2(1,1000);
normal_distribution<double> r3(1.0,20.0);
exponential_distribution<double> r4(5);

int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}


int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input3.txt","w",stdout);
    int t=20;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){
        int n=100000;
        int z=rng(10000000)+100000;
        multiset<int> s;
        while(s.size()<n){
            if(ii%5==4||ii%33==7){
                s.insert(z);
                continue;
            }
            int x=100000+rng(1000000);
            s.insert(x);
        }
        assert(s.size()==n);
        int sum=rng(100000)+200000;
        if(ii%5==4||ii%33==7)
            sum=z+z;
        cout<<n<<" ";
        for(auto &it:s)
            cout<<it<<" ";
        cout<<"\n";
        cout<<sum<<"\n";
    }
return 0;
}
