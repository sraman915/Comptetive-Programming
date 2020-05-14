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
int t=12;
cout<<t<<"\n";
for(int ii=0; ii<=t; ++ii){
if(ii==0){
cout<<"barfoothefoobarman\n";
cout<<2<<" "<<"foo "<<"bar\n";
}
else if(ii==1){
cout<<"catbatatecatatebat\n";
cout<<3<<" "<<"cat "<<"ate "<<"bat\n";
}
else if(ii==2){
cout<<"abcdababcd\n";
cout<<3<<" "<<"ab "<<"ab "<<"cd\n";
}
else{
string s;
int n=30+rng(15);
string a[n];
string ab,ba;
int nn=5+rng(10);
for(int i=0; i<n; ++i){
for(int j=0; j<nn; ++j){
char ch=rng(26)+'a';
a[i].pb(ch);
}
ab+=a[i];
}
ba=ab;
reverse(ab.begin(),ab.end());
char ch=rng(26)+'a';
s.pb(ch);
s+=ba;
int n1=4+rng(8);
for(int i=0; i<n1; ++i){
if(i%4==1){
s+=ab;
}
else{
ch=rng(26)+'a';
s.pb(ch);
}
}
s+=ba;
cout<<s<<"\n";
cout<<n<<" ";
for(int i=0; i<n; ++i)cout<<a[i]<<" ";
cout<<"\n";
}
}
return 0;}

