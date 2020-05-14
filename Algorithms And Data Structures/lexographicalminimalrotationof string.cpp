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

//booths algorithm

int f[mxn];

int ans(string s){
    s += s;
    int n = s.size();
    for(int i = 0; i < n; ++i)
        f[i] = -1;
    int k = 0;
    for(int j = 1; j < n; ++j){
        char ch = s[j];
        int i = f[j - k - 1];
        while(i != -1 && ch != s[k + i + 1]){
            if(ch < s[k + i + 1])
                k = j - 1 -i;
            i = f[i];
        }
        if(ch != s[k + i + 1]){
            if(ch < s[k])
                k = j;
            f[j - k] = -1;
        }
        else
            f[j - k] = i + 1;
    }
    return k;
}

int32_t main(){
sp;
    string s;
    cin>>s;
    int j = ans(s);
    string p;
    int n = s.size();
    p.push_back(s[j]);
    int i = (j + 1) % n;
    while(i != j){
        p.push_back(s[i]);
        ++i;
        i %= n;
    }
    cout<<p;
    return 0;
}
