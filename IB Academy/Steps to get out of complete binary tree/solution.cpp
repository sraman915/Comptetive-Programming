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

void solve(int n,int x){
	int fromroot[100];
	int fromleaf[100];
	int temp=n;
	int level=0;
	vector<int> ans;
	while(temp){
		fromroot[level]=min(temp,(1LL<<level));
		temp-=min(temp,(1LL<<level));
		level++;
	}
	level--;
	int left=(1LL<<level)-fromroot[level];
	for(int i=0;i<=level;i++){
		fromleaf[i]=fromroot[level-i];
	}
	for(int i=0;i<=level;i++){
		fromleaf[i+1]-=(left>>1);
		fromleaf[i]+=(left>>1);
		left>>=1;
	}
	if(x>level){
		cout<<0<<" "<<0<<" ";
	}
	else if(n==1){
		cout<<1<<" "<<1<<" ";
	}
	else cout<<fromroot[x]<<" "<<fromleaf[x]<<" ";
	cout<<"\n";
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,x;
cin>>n>>x;
assert(n>=1&&n<=100000000);
assert(x>=0&&x<=100);
solve(n,x);
}
return 0;}

