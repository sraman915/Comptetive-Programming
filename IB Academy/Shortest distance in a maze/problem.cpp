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
    int t=60;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){
    int n=80+rng(21);
    int m=80+rng(21);
    int tot=n*m;;
    int ones=100+rng(200);
    int a[n][m];
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
        int y=rng(2);
        if(y==1&&ones==0)y=0;
        if(y==1)--ones;
        a[i][j]=y;
        }
    }
    int startx=-1,starty=-1;
    int endx=-1,endy=-1;
    vector<pi> v;
    for(int i=0; i<n; ++i)
    for(int j=0; j<m; ++j){
    if(a[i][j]!=1)v.pb({i,j});
    }
    assert(v.size()>1);
    random_shuffle(v.begin(),v.end());
    startx=v.back().f;
    starty=v.back().s;
    v.pop_back();
    random_shuffle(v.begin(),v.end());
    endx=v.back().f;
    endy= v.back().s;
    assert(startx!=-1&&starty!=-1&&endx!=-1&&endy!=-1);
    assert(a[startx][starty]==0);
    assert(a[endx][endy]==0);
    cout<<n<<" "<<m<<" ";
    int yy=-1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
        if((j==m-1||i==n-1)&&yy==-1&&a[i][j]==0){
        endx=i;
        endy=j;
        yy=1;
        }
        cout<<a[i][j]<<" ";
        }
    }
    cout<<"\n";
    cout<<2<<" "<<startx<<" "<<starty<<"\n";
    cout<<2<<" "<<endx<<" "<<endy<<"\n";
}
return 0;
}
