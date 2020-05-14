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

int solveit(vector<vector<int> > &A){
    int n=A.size();
     int start[n];
     int end[n];
     for (int i=0; i<n; i++) {
       start[i]=A[i][0];
       end[i]=A[i][1];
     }
     sort(start,start+n);
     sort(end,end+n);
     int i=0, j=0, res=0;
     while (i<n) {
       if (start[i]<end[j])
        i++;
       else if (start[i]>end[j])
        j++;
       else {
         i++;
         j++;
       }
       res=max(res,i-j);
     }
     return res;
}


int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
int n,tempn;
cin>>n>>tempn;
assert(n>=1&&n<=100000);
assert(tempn==2);
vector<vector<int> > A(n,vector<int>(2));
for(int i=0; i<n; ++i){
    cin>>A[i][0]>>A[i][1];
    assert(A[i][0]<A[i][1]);
}
int ans=solveit(A);
cout<<ans<<"\n";
}
return 0;}
