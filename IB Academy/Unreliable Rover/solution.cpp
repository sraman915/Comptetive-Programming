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

const long long MOD = 1000000007;


int getArea(string &direction, vector <int> &minSteps, vector <int> &maxSteps) {
  int n = (int) direction.size();
  vector<int> unknown;
  int sx = 1, sy = 1;
  for (int i = 0; i < n; i++) {
    if (direction[i] == '?') {
      unknown.push_back(maxSteps[i]);
    } else {
      if (direction[i] == 'N' || direction[i] == 'S') {
        sy += maxSteps[i] - minSteps[i];
      } else {
        sx += maxSteps[i] - minSteps[i];
      }
    }
  }
  vector<int> sums;
  int sz = (int) unknown.size();
  for (int t = 0; t < (1 << sz); t++) {
    int sum = 0;
    for (int i = 0; i < sz; i++) {
      if (t & (1 << i)) {
        sum += unknown[i];
      }
    }
    sums.push_back(sum);
  }
  sort(sums.begin(), sums.end());
  int total = sums.back();
  long long ans = (long long) sx * sy + (long long) sx * total * 2 + (long long) sy * total * 2;
  ans += (long long) 2 * total * (total - 1);
  for (int i = 0; i < (int) sums.size() - 1; i++) {
    int cur = sums[i + 1] - sums[i];
    ans -= (long long) 2 * cur * (cur - 1);
  }
  return (ans%mod);
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
int ques=0;
int n;
cin>>n;
assert(s.size()==n);
for(auto &it:s){
assert(it=='N'||it=='S'||it=='E'||it=='W'||it=='?');
if(it=='?')++ques;
}
assert(ques<=20);
vector<int> B(n),C(n);
for(int i=0; i<n; ++i){
    cin>>B[i];
    assert(B[i]>=0&&B[i]<=10000000);
    }
cin>>n;
assert(s.size()==n);
assert(B.size()==n);
for(int i=0; i<n; ++i){
    cin>>C[i];
    assert(C[i]>=B[i]);
    assert(C[i]>=0&&C[i]<=10000000);
    }
int ans=getArea(s,B,C);
cout<<ans<<"\n";
}
return 0;}

