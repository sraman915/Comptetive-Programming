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


int32_t main(){
sp;
freopen("input2.txt","r",stdin);
freopen("output2.txt","w",stdout);
long long t;
cin >> t;
while (t--) {
   long long k, n, i, j, s = 0, s1 = 0, ans;
     cin >> n ;
     assert(n>=2&&n<=100000);
   long long a[n];
   for (i = 0; i < n; i++) {
   cin >> a[i];
   s += a[i];
   assert(a[i]>=1&&a[i]<=100000);
   }
   cin>>k;
   assert(k>=1&&k<n);
   sort(a, a+n);
   if (k <= n/2) {
   for (j = 0; j < k; j++) {
   s1 += a[j];
   }
   } else {
   for (j = n - 1; j > n - 1 - k; j--) {
   s1 += a[j];
   }
   }
   ans = s > 2*s1 ? s - (2*s1) : 2*s1 - s;
   cout << ans <<"\n";
}

return 0;}

