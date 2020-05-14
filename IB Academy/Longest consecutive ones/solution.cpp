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

int maximum_one(string &s) {
    // To count all 1's in the string
    int cnt_one = 0;
     int n=s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            cnt_one++;
    }

    // To store cumulative 1's
    int left[n], right[n];

    if (s[0] == '1')
        left[0] = 1;
    else
        left[0] = 0;

    if (s[n - 1] == '1')
        right[n - 1] = 1;
    else
        right[n - 1] = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '1')
            left[i] = left[i - 1] + 1;
        else
            left[i] = 0;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '1')
            right[i] = right[i + 1] + 1;

        else
            right[i] = 0;
    }

    int cnt = 0, max_cnt = 0;
    for(int i=0; i<n; ++i)
    max_cnt=max(max_cnt,max(right[i],left[i]));
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '0') {
            int sum = left[i - 1] + right[i + 1];

            if (sum < cnt_one)
                cnt = sum + 1;

            else
                cnt = sum;

            max_cnt = max(max_cnt, cnt);
            cnt = 0;
        }
    }

    return max_cnt;
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
string a;
cin>>a;
assert(a.size()>=1&&a.size()<=500000);
int ans=maximum_one(a);
cout<<ans<<"\n";
}
return 0;}
