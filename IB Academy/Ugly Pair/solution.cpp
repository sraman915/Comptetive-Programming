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

int a[27];

int solveit(string s) {
	int n=s.size();
	fill(a,a+27,0);
	for(int i=0; i<n; i++)
		a[s[i]-'a']++;
	for(int i=0; i<25; i++) {
		if(a[i]&&a[i+1]&&a[i]+a[i+1]==n)
            return 0;
	}

	for(int i=0; i<25; i++) {
		if(a[i]&&a[i+1]&&a[i+2]&&a[i]+a[i+1]+a[i+2]==n)
			return 0;
	}
	return 1;
}

bool check(string s){
	bool ok = true;
	for(int i=0; i+1<s.size(); ++i)
		ok &= (abs(s[i] - s[i + 1]) != 1);
	return ok;
}

int solveit1(string s){
    string odd = "", even = "";
		for(int i=0; i<s.size();++i){
			if (s[i] % 2 == 0)
				odd += s[i];
			else
				even += s[i];
		}
		sort(odd.begin(),odd.end());
		sort(even.begin(),even.end());
		if (check(odd + even))
			return 1;
		else if (check(even + odd))
			return 1;
		return 0;
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
        assert(s.size()>=1&&s.size()<=100);
        for(auto &it:s)
            assert(it>='a'&&it<='z');
        int ans=solveit(s);
        cout<<ans<<"\n";
    }
    return 0;
}
