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
    int t=10;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){
    string s,t;
    int n=100000;
    int m=1+rng(n);
    int z=26;
    if(ii==1||ii==10){
    m=1;
    z=1;
    }
    else if(ii==2){
    m=2;
    z=2;
    }
    else if(ii==3||ii==4||ii==8){
    m=3;
    z=3;
    }
    for(int i=0; i<n; ++i){
    char ch=rng(z)+'a';
    s.push_back(ch);
    }
    for(int i=0; i<m; ++i){
    char ch=rng(z)+'a';
    t.push_back(ch);
    }

    if(ii%7==0){
    cout<<s<<"\n";
    cout<<t<<"\n";
    continue;
    }
    cout<<s<<"\n";
    cout<<t<<"\n";
}
return 0;
}
