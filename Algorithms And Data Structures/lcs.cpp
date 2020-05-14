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

int32_t main() {
sp;
    int n, m;
    cin>>n>>m;
    int a[n + 1], b[m + 1];
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    for(int j = 1; j <= m; ++j)
        cin>>b[j];
    int lcs[n + 1][m + 1];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j){
            if(i == 0 || j == 0)
                lcs[i][j] = 0;
            else if(a[i] == b[j])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    int i = n, j = m;
    vector<int> v;
    while(i > 0 && j > 0){
        if(a[i] == b[j]){
            v.push_back(a[i]);
            --i, --j;
        }
        else if(lcs[i][j-1] > lcs[i-1][j])
            --j;
        else
            --i;
    }
    while(!v.empty()){
        cout<<v.back()<<" ";
        v.pop_back();
    }
    return 0;
}
