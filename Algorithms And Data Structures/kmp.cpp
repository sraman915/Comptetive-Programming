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

int32_t main() {
sp;
    int t;
    cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        calc(b);
        int n = a.size(), l = b.size();
        int i = 0, j = 0, c = 0;
        vector<int> v;
        while(i<n){
            if(b[j] == a[i])
                ++i, ++j;
            if(j == l){
                ++c;
                v.push_back(1 + i - j);
                j = lps[j - 1];
            }
        else if(i < n && a[i] != b[j]){
            if(j)
                j = lps[j - 1];
            else
                ++i;
        }
    }
    if(c){
        cout<<c<<"\n";
        for(int i = 0; i < v.size(); ++i)
            cout<<v[i]<<" ";
        cout<<"\n";
    }
    else
        cout<<"Not Found\n";
    cout<<"\n";
    }
    return 0;
}
