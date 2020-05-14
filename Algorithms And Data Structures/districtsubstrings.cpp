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

int lcpsize(string &a, string &b){
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    int x = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            ++x;
            ++i;
            ++j;
        }
        else
            return x;
    }
    return x;
}

int32_t main(){
sp;
    int t;
    cin>>t;
    while(t--){
        vector<string> v;
        string s;
        cin>>s;
        string p;
        for(int i = s.size()-1; i >= 0; --i){
            p.push_back(s[i]);
            v.push_back(p);
        }
        for(auto &it:v)
            reverse(it.begin(),it.end());
        sort(v.begin(),v.end());
        int ans = v[0].size();
        for(int i = 1; i < v.size(); ++i){
            int y = lcpsize(v[i], v[i-1]);
            ans += v[i].size() - y;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
