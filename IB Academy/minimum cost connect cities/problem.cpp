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
    int t=8;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){

            int n=70000+rng(20000);
            map<pi,int> mp;
        vector<int> v1,v2;
        for(int i=1; i<=n; ++i)
            v2.pb(i);
            vector<pi> v;
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
            v.pb({v1[p1],v2[p2]});
            mp[{v1[p1],v2[p2]}];
            mp[{v2[p2],v1[p1]}];
            swap(v2[p2],v2[n2-1]);
            v1.pb(v2.back());
            v2.pop_back();
        }
    }
    assert(v.size()==n-1);
    int tot=(n*(n-1))/2;
    int rem=tot-n+1;
    int m=100000;
    for(int i=n; i>=1; --i){
    if(v.size()==m)break;
        for(int j=i-1; j>0; --j){
        if(v.size()==m)break;
        if(mp.find({i,j})!=mp.end())continue;
        mp[{i,j}];
        mp[{j,i}];
        v.pb({i,j});
        }
    }
    cout<<n<<"\n";
    assert(v.size()==m);
    cout<<m<<" "<<3<<" ";
    for(auto &it:v)
    cout<<it.first<<" "<<it.second<<" "<<(1+rng(1000))<<" ";
    cout<<"\n";
}
return 0;
}
