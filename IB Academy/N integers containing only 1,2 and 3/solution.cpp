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

vector<int> doit(int n){
vector<int> ans;
queue<int>q ;
q.push(1);
q.push(2);
q.push(3);
int mx=1000000000;
while(ans.size()<n){
int x=q.front();
q.pop();
ans.push_back(x);
int x1=x*10+1;
int x2=x*10+2;
int x3=x*10+3;
if(x1<mx)
q.push(x1);
if(x2<mx)
q.push(x2);
if(x3<mx)
q.push(x3);
}
return ans;
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
assert(n>=1&&n<=29500);
vector<int> ans=doit(n);
for(auto &it:ans)cout<<it<<" ";
cout<<"\n";
}
return 0;}
