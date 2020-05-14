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

int minRefuelStops(int A, int B, vector<int> C,vector<int> D) {
      assert(A >=1 && A <= 1000000000);
      assert(B >=1 && B <= 1000000000);
      int n=C.size();
      assert(A > C[n-1]);
      assert(C.size()==D.size());
      assert(n>=1&&n<=50000);
      for(auto &it:D)
      assert(it >=1 && it <= 1000000000);
      for(int i=1; i<n; ++i)
      assert(C[i]>C[i-1]);
        int i = 0, res;
        priority_queue<int>pq;
        for (res = 0; B < A; res++){
            while (i < C.size() && C[i] <= B)
                pq.push(D[i++]);
            if (pq.empty())
                   return -1;
            B += pq.top(), pq.pop();
        }
        return res;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
int A,B;
cin>>A>>B;
int n;
cin>>n;
vector<int> C(n),D(n);
for(int i=0; i<n; ++i)cin>>C[i];
cin>>n;
for(int i=0; i<n; ++i)cin>>D[i];
cout<<minRefuelStops(A,B,C,D)<<"\n";
}
return 0;}
