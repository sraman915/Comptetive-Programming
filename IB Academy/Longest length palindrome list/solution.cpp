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

int ans(vector<int> a){
int n=a.size();
int ans=1;
for(int i=0; i<a.size(); ++i){

for(int j=i,k=i+1; j>=0&&k<a.size(); --j,++k){
if(a[j]==a[k])ans=max(ans,k+1-j);
else break;
}

for(int j=i,k=i; j>=0&&k<a.size(); --j,++k){
if(a[j]==a[k])ans=max(ans,k+1-j);
else break;
}

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
vector<int> a(n);
for(int i=0; i<n; ++i)cin>>a[i];
int mx=ans(a);
cout<<mx<<"\n";
}
return 0;}
