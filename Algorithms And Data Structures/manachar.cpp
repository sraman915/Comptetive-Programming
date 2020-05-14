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

int p[mxn * 2 + 1];

string convert(string &s){
    string nw = "@";
    for(int i = 0; i < s.size(); ++i)
        nw += "#" + s.substr(i, 1);
    nw += "#$";
    return nw;
}

string longestpalindrome(string &s){
    string q = convert(s);
    int n = q.size();
    int c = 0, r = 0;
    for(int i = 1; i < n - 1; ++i){
        int mirror = c - (i - c);
        if(r > i)
            p[i] = min(r - i, p[mirror]);
        while(q[i + 1 + p[i]] == q[i - 1 - p[i]])
            p[i]++;
        if(i + p[i] > r){
            c = i;
            r = i + p[i];
        }
    }
    int mx = 0, cx = 0;
    for(int i = 1; i < n - 1; ++i){
        if(p[i] > mx){
            mx = p[i];
            cx = i;
        }
    }
    return s.substr((cx - 1 - mx)/2, mx);
}

int32_t main(){
sp;
    string s;
    cin>>s;
    string ans = longestpalindrome(s);
    cout<<ans.size()<<"\n"<<ans;
    return 0;
}
