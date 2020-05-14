#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 400005

int p[mxn];

void init(){
p[0]=1LL;
for(int i=1; i<mxn; ++i)
    p[i]=(p[i-1]*101LL)%mod;
}

int32_t main(){
sp;
    init();
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int m,n=s.size(),ans=0;
        m=n+n;
        s=s+s;
        int pf[m+1],sf[m+1];
        memset(pf,0,sizeof pf);
        memset(sf,0,sizeof sf);
        for(int i=0; i<m; ++i){
            if(i)
                pf[i]=(pf[i-1]+(s[i]-'a'+1)*p[i])%mod;
            else
                pf[i]=(s[i]-'a'+1);
        if(i)
            sf[m-1-i]=(sf[m-i]+(s[i]-'a'+1)*p[i])%mod;
        else
            sf[m-1-i]=s[i]-'a'+1;
        }
        int h1=0,h2=0;
        int l,r;
        for(int i=0; i<n; ++i){
            l=i;
            r=i+n-1;
            h1=pf[r];
            if(l)
                h1-=pf[l-1];
            if(h1<0)
                h1+=mod;
            h2=sf[l];
            if(r+1<m)
                h2-=sf[r+1];
            if(h2<0)
                h2+=mod;
            h1=(h1*p[m-r-1])%mod;
            h2=(h2*p[l])%mod;
            if(h1==h2)
                ++ans;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
