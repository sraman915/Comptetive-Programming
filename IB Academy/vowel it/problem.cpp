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

int32_t main(){
sp;
freopen("input2.txt","w",stdout);
srand(time(NULL));
int t=500;
cout<<t<<"\n";
for(int i=0; i<t; ++i){
    string a;
    int n=15;
    if(i&1)
    n-=i%7;
    else n+=i%7;
    a.pb('a');
    for(int i=2; i<=n; ++i){
        int z=rand()%26;
        a.pb(z+'a');
    }
    assert(a.size()>=1&&a.size()<=100000);
cout<<a<<"\n";
}
return 0;}

