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

int a[mxn],p[2005],p4[2005],p8[2005],p14[2005],p20[2005];
const int block=1005;
string s;
int tot;
int d[5001][2002];


int query(int l,int r){
    int b1=l/block;
    int x=0;
    int i=l;
    while(i/block==b1&&i<=r){
        if(a[i]%26==p[b1])
            ++x;
        else if(a[i]%26==p4[b1])
            ++x;
        else if(a[i]%26==p8[b1])
            ++x;
        else if(a[i]%26==p14[b1])
            ++x;
        else if(a[i]%26==p20[b1])
            ++x;
        ++i;
    }
    ++b1;
    while(b1<r/block){
        x+=d[b1][p[b1]];
        x+=d[b1][p4[b1]];
        x+=d[b1][p8[b1]];
        x+=d[b1][p14[b1]];
        x+=d[b1][p20[b1]];
        ++b1;
    }
    i=b1*block;
    while(i<=r){
        if(a[i]%26==p[b1])
            ++x;
        else if(a[i]%26==p4[b1])
            ++x;
        else if(a[i]%26==p8[b1])
            ++x;
        else if(a[i]%26==p14[b1])
            ++x;
        else if(a[i]%26==p20[b1])
            ++x;
        ++i;
    }
    return x;
}

void update(int l,int r,int y){
    int b1=l/block;
    int i=l;
    while(i/block==b1&&i<=r){
        int z=a[i];
        d[b1][z]--;
        z=(z+y)%26;
        d[b1][z]++;
        a[i]=z;
        ++i;
    }
    ++b1;
    while(b1<r/block){
        p[b1]=(p[b1]-y+26)%26;
        p4[b1]=(p4[b1]-y+26)%26;
        p8[b1]=(p8[b1]-y+26)%26;
        p14[b1]=(p14[b1]-y+26)%26;
        p20[b1]=(p20[b1]-y+26)%26;
        ++b1;
    }
    i=b1*block;
    while(i<=r){
        int z=a[i];
        d[b1][z]--;
        z=(z+y)%26;
        d[b1][z]++;
        a[i]=z;
        ++i;
    }
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        s.clear();
        cin>>s;
        int n=s.size();
        for(int i=0; i<n; ++i)
            a[i]=s[i]-'a';
        tot=(n+block-1)/block;
        for(int i=0; i<=tot+1; ++i)
            for(int j=0; j<=block+1; ++j)
                d[i][j]=0;
        for(int i=0; i<n; ++i)
            ++d[i/block][a[i]];
        for(int i=0; i<=block+1; ++i){
            p[i]=0;
            p4[i]=4;
            p8[i]=8;
            p14[i]=14;
            p20[i]=20;
        }

        char c;
        int q;
        cin>>q;
        while(q--){
            cin>>c;
            if(c=='F'){
                int l,r;
                cin>>l>>r;
                --l;
                --r;
                cout<<query(l,r)<<"\n";
            }
            else{
                int l,r,y;
                cin>>l>>r>>y;
                y%=26;
                if(y){
                    --l;
                    --r;
                    update(l,r,y);
                }
            }
        }
    }
    return 0;
}
