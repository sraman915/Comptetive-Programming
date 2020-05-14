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


string encodedChar(string &str, int &k){
    int i, j;

    int n = str.size();
    assert(n>=1&&n<=100000);
    assert(k>=1&&k<=1000000000);
    int len;
    int num;
    int freq;
  string ans;
    i = 0;

    while (i < n) {
        j = i;
        len = 0;
        freq = 0;
        while (j < n && isalpha(str[j])) {
            j++;
            len++;
        }
        while (j < n && isdigit(str[j])) {
            freq = freq * 10 + (str[j] - '0');
            j++;
        }
        num = 1LL*freq * len;
        if (k > num) {
            k -= num;
            i = j;
        }
        else {
            k--;
            k %= len;
            assert(i+k<n);
            ans.push_back(str[i+k]);
            return ans;
        }
    }
    ans.push_back(str[k-1]);
    return ans;
}


int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
string a;
int b;
cin>>a>>b;
string ans=encodedChar(a,b);
cout<<ans<<"\n";
}
return 0;}
