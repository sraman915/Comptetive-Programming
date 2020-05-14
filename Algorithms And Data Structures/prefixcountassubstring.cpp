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

int lps[mxn];

void calc(string &s){
    int l = s.size();
    lps[0] = 0;
    int i = 1, len = 0;
    while(i < l){
        if(s[i] == s[len]){
            ++len;
            lps[i] = len;
            ++i;
        }
        else{
            if(len)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
}

int ans[mxn];

void countofeachprefix(string &s){
    calc(s);
    int n = s.size();
    for(int i = 0; i < s.size(); ++i)
        ++ans[lps[i]];
    for(int i = n - 1; i > 0; --i)
        ans[lps[i - 1]] += ans[i];
    for(int i = 0; i <= n; ++i)
        ++ans[i];

    for(int i = 1;i <= n; ++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int32_t main(){
sp;
    string s;
    cin>>s;
    countofeachprefix(s);
    return 0;
}
