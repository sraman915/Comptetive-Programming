#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
//#define mod (long long)1000000007
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

const int mod = 1000000007;

int bruteforce(vector<int> &a){
    int n=a.size();
    long long ans=-1;
    for(int i=0; i+2<n; ++i)
        for(int j=i+1; j+1<n; ++j)
            for(int k=j+1; k<n; ++k){
                    if(a[i]<a[j]&&a[j]<a[k]){
                        long long temp=1LL*a[i]*a[j]*a[k];
                        if(ans<temp)
                            ans=temp;
                    }
                }
    if(ans!=-1)
        ans%=mod;
    return (int)(ans);
}

int solveit(vector<int> &a){
    //return bruteforce(a);
    int n=a.size();
    long long ans=-1;
    long long smaller[n];
    set<long long> s;
    memset(smaller,-1,sizeof smaller);
    set<long long>::iterator it;

    for(int i=0; i<n; ++i){
        s.insert(a[i]);
        it=s.lower_bound(a[i]);
        if(it!=s.begin()){
            --it;
            smaller[i]=*it;
        }
    }
    long long suffixmax=a[n-1];
    for(int i=n-2; i>0; --i){
        if(a[i]>suffixmax)
            suffixmax=a[i];
        else if(smaller[i]!=-1){
            long long temp=1LL*smaller[i]*a[i]*suffixmax;
            if(ans<temp)
                ans=temp;
        }
    }
    if(ans!=-1)
        ans%=mod;
    return (int)(ans);
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
        assert(n>=1&&n<=100000);
        vector<int> a(n);
        for(int i=0; i<n;++i){
            cin>>a[i];
            assert(a[i]>=1&&a[i]<=1000000);
        }
        int ans=solveit(a);
        cout<<ans<<"\n";
    }
    return 0;
}
