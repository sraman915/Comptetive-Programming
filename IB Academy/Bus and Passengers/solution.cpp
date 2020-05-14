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

struct Element {
	int value, index;
};
bool compareElement(const Element &e1, const Element &e2)
{
    return (e1.value < e2.value);
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    long long n, j;
	cin >> n;
	assert(n>=1&&n<=100000);
	struct Element e[n];
	unordered_set<int> ss;
	for (int i = 0; i < n; i++) {
		cin >> j;
		ss.insert(j);
		e[i].value = j;
		e[i].index = i;
	}
	assert(ss.size()==n);
	sort(e, e+n, compareElement);
	char s[2*n + 2];
	cin >> s;
	long long a[2*n];
	long long c = 0, c1 = 0;
	for (int i = 0; s[i] != '\0'; i++) {
            assert(s[i]=='0'||s[i]=='1');
		if (s[i] == '0') {
			cout << e[c1++].index + 1 << " ";
			a[c++] = c1 - 1;
		} else {
			cout << e[a[--c]].index + 1 << " ";
		}
	}
	cout<<"\n";

}
return 0;}
