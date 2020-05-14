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

struct Job {
   int dead;
   int profit;
};

bool compare(const Job &a, const Job &b) {
     return (a.profit > b.profit);
}

int solveit(vector<int> &A,vector<int> &B){
    int n=A.size();
    Job a[n];
    for(int i=0; i<n; ++i){
        a[i].dead=A[i];
        a[i].profit=B[i];
    }
    sort(a,a+n,compare);
    int result[n];
    bool slot[n];
    for (int i=0; i<n; i++)
        slot[i] = false;
    for(int i=0; i<n; i++) {
       for (int j=min(n, a[i].dead)-1; j>=0; j--) {
            if(slot[j]==false) {
                result[j] = i;
                slot[j] = true;
                break;
          }
       }
    }
    int ans=0;
    for(int i=0; i<n; i++)
       if(slot[i])
            ans+=a[result[i]].profit;

    return ans;
}

int32_t main(){
sp;
freopen("input3.txt","r",stdin);
freopen("output3.txt","w",stdout);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    assert(n>=1&&n<=1000);
    vector<int> deadline(n),profit(n);
    int tn;
    for(int i=0; i<n; ++i)
        cin>>deadline[i];
    cin>>tn;
    assert(tn==n);
    for(int i=0; i<n; ++i){
        cin>>profit[i];
        assert(profit[i]<=100000);
    }
    int ans=solveit(deadline,profit);
    cout<<ans<<"\n";
}
return 0;}
