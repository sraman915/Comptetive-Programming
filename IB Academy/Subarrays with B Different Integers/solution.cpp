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

unordered_map<int,int> mp;

void add(int x){
    ++mp[x];
}

void removee(int x){
    --mp[x];
    if(mp[x]==0)
        mp.erase(x);
}

int solveit(vector<int>& A, int K) {
    mp.clear();
    int n=A.size();
    if(n<K)
        return 0;
    int l = 0, r = 0, d = 0, ans = 0;
    while (r <= n) {
        if (r < n && mp.size() < K)
            add(A[r++]);
        else if(mp.size()==K) {
            if(d<=r){
                d = r;
                while(d < n && mp.find(A[d]) != mp.end())
                    d++;
            }
            while(mp.size()==K){
                ans+=(d+1-r);
                removee(A[l++]);
            }
        }
        else
            r++;
    }
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
        assert(n>=1&&n<=40000);
        vector<int> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
            assert(a[i]>=1&&a[i]<=n);
        }
        int k;
        cin>>k;
        assert(k>=1&&k<=n);
        int ans=solveit(a,k);
        cout<<ans<<"\n";
    }
    return 0;
}
