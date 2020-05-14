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

int P[16][50001];

struct entry{
    int i,nr[2];
};
struct entry L[50001];

bool cmp(const entry &a, const entry &b){
    if(a.nr[0] == b.nr[0])
        return a.nr[1] < b.nr[1];
    else
        return a.nr[0] < b.nr[0];
}

int stp = 1;

void compute_suffix_array(string s){
    int i,l;
    l = s.size();
    for(i = 0; i < l; i++)
        P[0][i] = s[i];
    int cnt = 1;
    while(cnt < l){
        for(i = 0; i < l;i++){
            L[i].i = i;
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = i + cnt < l ? P[stp - 1][i + cnt] : -1;
        }
        sort(L, L+l, cmp);
        int rank = 0;
        for(i = 0;i < l; i++){
            if(i-1 >= 0){
                if(L[i].nr[0] != L[i-1].nr[0] || L[i].nr[1] != L[i-1].nr[1])
                    rank++;
            }
            P[stp][L[i].i] = rank;
        }
        cnt = cnt<<1;
        stp++;
    }
}

int lcp(string s,int x, int y){
    if(x == y)
        return s.size() - x;
    int ans  = 0;
    int i;
    for(i = stp - 1; i >= 0 && x < s.length() && y < s.length(); i--){
        if(P[i][x] == P[i][y]){
            ans += 1<<i;
            x += 1<<i;
            y += 1<<i;
        }
    }
    return ans;
}

int countDistinctSubstring(string s){
    stp = 1;
    compute_suffix_array(s);
    int l = s.size();
    int temp = 0;
    for(int i = 0; i < l-1; i++){
        temp = temp + lcp(s,L[i].i,L[i+1].i);
    }
    int l1 = s.size();
    int ans = (l1 * (l1 + 1)) / 2 - temp;
    return ans;
}

int32_t main(){
sp;
    string s;
    cin>>s;
    cout<<countDistinctSubstring(s)<<"\n";
    return 0;
}
