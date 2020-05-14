#include<bits/stdc++.h>
#include<random>
#include<chrono>

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
#define mxn 200005

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
int t=15;
cout<<t<<"\n";
for(int ii=1; ii<=t; ++ii){
string a;
int k;
char ch=rng(26)+'a';
a.pb(ch);
int n=100000;
int sum=0,prev=0;
for(int i=1; i<n; ++i){
if(i%10==5){
int x=1+rng(9)+'0';
prev=x-'0';
a.pb(x);
}
else if(i%10>5){
int y=rng(10)+'0';
prev=prev*10+y-'0';
sum+=prev;
a.pb(y);
prev=0;
}
else{
ch=rng(26)+'a';
a.pb(ch);
}
}
cout<<a<<"\n";
k=1+rng(1000000000);
cout<<k<<"\n";
}

return 0;}
