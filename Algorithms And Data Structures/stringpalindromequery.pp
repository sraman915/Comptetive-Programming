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
#define mxn 1000005

string s;
int n;
int base=31LL;
int p1[mxn],p2[mxn];
int fronthash[mxn],backhash[mxn];

void pre(){
    p1[0]=1LL;
    for(int i=1;i<=n; ++i)
        p1[i]=(1LL*p1[i-1]*base)%mod;
    for(int i=n; i>0; --i)
        p2[i]=p1[n+1-i];
}

void pre1(){
    for(int i=1; i<=n; ++i){
        fronthash[i]=(1LL*p1[i]*s[i])%mod;
        backhash[i]=(1LL*p2[i]*s[i])%mod;
        fronthash[i]+=fronthash[i-1];
        while(fronthash[i]>=mod)
            fronthash[i]-=mod;
    }
    for(int i=n-1; i>0; --i){
        backhash[i]+=backhash[i+1];
        while(backhash[i]>=mod)
            backhash[i]-=mod;
    }

}


int32_t main(){
sp;
    cin>>s;
    n=s.size();
    assert(n>=1&&n<=1000000);
    s=" "+s;
    pre();
    pre1();
    int q,x;
    cin>>q;
    assert(q>=1&&q<=100000);
    while(q--){
        cin>>x;
        assert(x>=1&&x<=n);
        if(x==1||x==n){
            cout<<"1\n";
            continue;
        }
        int ans=0,l,r,m;
        l=0;
        r=min(n-x,x-1);
        while(l<=r){
            m=(l+r)>>1;
            int hash1=0;
            int hash2=0;
            hash1=fronthash[x-1]-fronthash[x-1-m];
            hash2=backhash[x+1]-backhash[x+1+m];
            hash1+=mod;
            hash2+=mod;
            while(hash1>=mod)
                hash1-=mod;
            while(hash2>=mod)
                hash2-=mod;
            int leftdistanceh1=x-m;
            int leftdistanceh2=n+1-(x+m);
            if(leftdistanceh1>leftdistanceh2)
                hash2=(1LL*hash2*p1[leftdistanceh1-leftdistanceh2])%mod;
            else if(leftdistanceh1<leftdistanceh2)
                hash1=(1LL*hash1*p1[leftdistanceh2-leftdistanceh1])%mod;
            if(hash1==hash2){
                ans=m;
                l=m+1;
            }
            else
                r=m-1;
        }
        cout<<ans+1<<"\n";
    }
    return 0;
}

