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
    int t=5;
    cout<<t<<"\n";
    string A;
    A.pb('?');
    A.pb('N');
    A.pb('S');
    A.pb('E');
    A.pb('W');
    for(int ii=1; ii<=t; ++ii){
    int n=45;
    string s;
    int mx=20;
    for(int i=0; i<n; ++i){
    char ch=A[rng(5)];
    if(ii%2==1&&i%2==1)ch='?';
    if(ch=='?'){
    if(mx>0){
    s.push_back(ch);
    --mx;
    continue;
    }
    while(ch=='?'){
    ch=A[rng(5)];
    }
    s.push_back(ch);
    }
    else
        s.push_back(ch);
    }

   assert(s.size()==n);
   vector<int> b(n),c(n);
   for(int i=0; i<n; ++i){
   if(s[i]=='?')b[i]=0;
   else b[i]=rng(1000000);
   c[i]=b[i]+rng(1000000);
   }
   cout<<s<<"\n";
   cout<<n<<" ";
   for(auto &it:b)cout<<it<<" ";
   cout<<"\n";
   cout<<n<<" ";
   for(auto &it:c)cout<<it<<" ";
   cout<<"\n";
}
return 0;
}
