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
    for(int ii=1; ii<=t; ++ii){
    int n=100000;
    vector<int> type(n);
    vector<string> key(n,"null");
    vector<string> value(n,"null");
    vector<int> timestamp(n,0);
    vector<pair<string,string> > v;
    int prev=0;
    for(int i=0; i<n; ++i)
    type[i]=1+rng(2);
    for(int i=0; i<n; ++i){
    if(type[i]==1){
    string s1,s2;
    int n1=4+rng(10);
    int n2=4+rng(10);
    for(int i=0; i<n1; ++i)
        s1.push_back(rng(26)+'a');
    for(int i=0; i<n2; ++i)
        s2.push_back(rng(26)+'a');
    key[i]=s1;
    value[i]=s2;
    v.push_back({s1,s2});
    timestamp[i]=prev+1+rng(100);
    prev=timestamp[i];
    }
    else{
    if(!v.empty()){
    //random_shuffle(v.begin(),v.end());
    int zz=(rng((int)v.size()));
    key[i]=v[zz].first;
    value[i]="null";
    timestamp[i]=3+rng(2000);
    }
    else{
    string s1;
    int n1=3+rng(10);
    for(int i=0; i<n1; ++i)
        s1.push_back(rng(26)+'a');
    key[i]= s1;
    timestamp[i]=3+rng(20);
    }
    }
    }

    //for(int i=0; i<n; ++i){
    //cout<<type[i]<<" "<<key[i]<<" "<<value[i]<<" "<<timestamp[i]<<"\n";
    //}
    cout<<n<<" ";
    for(auto &it:type)cout<<it<<" ";
    cout<<"\n";
    cout<<n<<" ";
    for(auto &it:key)cout<<it<<" ";
    cout<<"\n";
    cout<<n<<" ";
    for(auto &it:value)cout<<it<<" ";
    cout<<"\n";
    cout<<n<<" ";
    for(auto &it:timestamp)cout<<it<<" ";
    cout<<"\n";
}
return 0;
}
