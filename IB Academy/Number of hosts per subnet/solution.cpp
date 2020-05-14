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

int checkunset(int x){
    int notset=0;
    for(int i=0; i<8; ++i)
        if(x&(1<<i));
        else
            ++notset;
    return notset;
}

int solveit(string s){
    int n=s.size();
    int unset=0;
    int prev=0;
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='.'){
            unset+=checkunset(prev);
            prev=0;
        }
        else
            prev=prev*10+(s[i]-'0');
    }
    unset+=checkunset(prev);
    if(unset<=1)
        return 0;
    int ans=1;
    for(int i=0; i<unset; ++i)
        ans=ans*2;
    return (ans-2);
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
    int ans=solveit(s);
    cout<<ans<<"\n";
}
return 0;}
