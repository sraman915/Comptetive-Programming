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

int solve(int n){
if(n==0)return 0;
return __builtin_popcount(n);
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n;
cin>>n;
assert(n>=0&&n<=1000000000);
cout<<solve(n)<<"\n";

}
return 0;}
