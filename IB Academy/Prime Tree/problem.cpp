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

void random_tree(int n){
    vector<int> v1,v2;
    for(int i=1; i<=n; ++i)
        v2.pb(i);
    int x=n;
    while(x--){
        if(v1.empty()){
            int n1=v2.size();
            int p=rand()%n1;
            v1.pb(v2[p]);
            swap(v2[p],v2[n1-1]);
            v2.pop_back();
        }
        else{
            int n1=v1.size();
            int n2=v2.size();
            int p1=rand()%n1;
            int p2=rand()%n2;
            cout<<v1[p1]<<" "<<v2[p2]<<" ";
            swap(v2[p2],v2[n2-1]);
            v1.pb(v2.back());
            v2.pop_back();
        }
    }
}

int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input3.txt","w",stdout);
    int t=5;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){
        int n=200000;
        cout<<n<<"\n";
        cout<<n<<" ";
        for(int i=1; i<=n; ++i)
            cout<<1+rng(300)<<" ";
        cout<<"\n";
        cout<<n-1<<" "<<2<<" ";
        random_tree(n);
        cout<<"\n";
        int q=200000;
        cout<<q<<" "<<3<<" ";
        for(int i=0; i<q; ++i){
            int type=rng(2);
            int val1=1+rng(n);
            int val2=0;
            if(type==0)
                val2=1+rng(300);
            cout<<type<<" "<<val1<<" "<<val2<<" ";
        }
        cout<<"\n";
    }
return 0;
}
