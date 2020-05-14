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


const int N = 2e5 + 5;

int L[N], R[N];
vector<int>  p[30];

int clean(int n){

for(int i=0;i<30; ++i)
    p[i].clear();
for(int i=0; i<=n; ++i)
    L[i]=R[i]=0;
}

int doit(string &str,string &T){
	int n = str.length();
	int m = T.length();
	clean(max(n,m));
	int j = 0;
	for (int i = 0; i <= m; ++i)
        L[i] = n, R[i] = -1;
	R[m] = n;
	for (int i = 0; i < n; i++) {
		if (j < m && str[i] == T[j]) {
			L[j] = i;
			j++;
			continue;
		}
	}
	j = m - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (j >= 0 && str[i] == T[j]) {
			R[j] = i;
			j--;
		}
	}
	for (int i = 0; i < m; ++i) {
		p[T[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int k = str[i] - 'a';
		if (p[k].size() == 0 || L[p[k][0]] > i) {
			return 0;
		}
		int l = 0, r = p[k].size() - 1;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (L[p[k][mid]] <= i) l = mid;
			else r = mid - 1;
		}
		if (R[p[k][l] + 1] <= i) {
			return 0;
		}
	}
	return 1;
}



int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
string s,t;
cin>>s>>t;
assert(s.size()>=1&&s.size()<=100000);
assert(t.size()>=1&&t.size()<=100000);
for(auto &it:s)
assert(it>='a'&&it<='z');
for(auto &it:t)
assert(it>='a'&&it<='z');
cout<<doit(s,t)<<"\n";
}
return 0;}
