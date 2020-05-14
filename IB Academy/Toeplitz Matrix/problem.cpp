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

void print(vector<vector<int> > &v){
cout<<v.size()<<" "<<v[0].size()<<" ";
for(auto &it:v)
for(auto &it1:it)cout<<it1<<" ";
cout<<"\n";
}

vector<vector<int> > ToeplitzMatrix(int n,int m){
vector<vector<int> > v(n,vector<int>(m));
for(int i=0; i<m; ++i)
v[0][i]=1+rng(200);
for(int i=1; i<n; ++i){
    for(int j=0; j<m; ++j){
        if(j-1>=0&&i-1>=0)v[i][j]=v[i-1][j-1];
        else v[i][j]=1+rng(200);
    }
}
return v;
}


int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input3.txt","w",stdout);
    int t=5;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){
    int n=500;
    int m=500;
    vector<vector<int> > v=ToeplitzMatrix(n,m);
    int z=rng(2);
    if(z==1){
    int x=rng(n);
    int y=rng(m);
    v[x][y]=1+rng(200);
    }
    print(v);
}
return 0;
}
