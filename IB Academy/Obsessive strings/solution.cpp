#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

#define ll long long
const int md = 1000000007;
const int N = 100005;
int lcp[N];
bool found[N];
ll dp[N],predp[N],prepredp[N];

void clean(int n){
    for(int i=0; i<=n; ++i){
        dp[i]=0;
        predp[i]=0;
        prepredp[i]=0;
        found[i]=0;
        lcp[i]=0;
    }
}

int doit(string &s,string &t){
    int n = s.size();
	int m = t.size();
	if(m>n)
        return 0;
    clean(n);
	int j = 0;
	for(int i=1;i<m;i++){
		while(j>0){
			if(t[j] == t[i]){
				lcp[i] = ++j;
				break;
			}
			else
				j = lcp[j-1];
		}
		if(j==0){
			if(t[i] == t[j])
				lcp[i] = ++j;
			else
				lcp[i] = 0;
		}
	}
	j = 0;
	for(int i=0;i<n;i++){
		while(j>0){
			if(s[i] == t[j]){
				j++;
				break;
			}
			else
				j = lcp[j-1];
		}
		if(j==0){
			if(s[i] == t[j])
				j++;
		}
		if(j==m){
			found[i-m+1] = 1;
		}
	}
	j = -1;
	ll ans = 0;
	for(int i=m-1;i<n;i++)
	{
		if(found[i-m+1])
			j = i-m+1;
		if(j==-1)
			continue;
		dp[i] = (prepredp[j-1]+j+1)%md;
		ans = (ans + dp[i])%md;
		predp[i] = (predp[i-1]+dp[i])%md;
		prepredp[i] = (prepredp[i-1]+predp[i])%md;
	}
	return (int)(ans);
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
int ans=doit(s,t);
cout<<ans<<"\n";
}
return 0;}
