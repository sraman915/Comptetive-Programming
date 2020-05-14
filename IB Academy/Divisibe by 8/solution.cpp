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

int ans(string &s){
int n=s.size();
if(n==1)
return ((s[0]-'0')%8==0);
if(n==2) {
int x=(s[0]-'0')*10+s[1]-'0';
return (x%8==0);
}
int a3=(s[n-3]-'0')*100+(s[n-2]-'0')*10+(s[n-1]-'0');
return (a3%8==0);
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
string s;
cin>>s;
cout<<ans(s)<<"\n";
}
return 0;}

