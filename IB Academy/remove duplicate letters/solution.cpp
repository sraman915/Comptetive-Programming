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

string removeDuplicateLetters(string &s) {
    vector<int> cand(256, 0);
    vector<bool> visited(256, false);
    for (char c : s)
        cand[c]++;
    string result = "0";
    for (char c : s) {
        cand[c]--;
        if (visited[c]) continue;
        while (c < result.back() && cand[result.back()]) {
            visited[result.back()] = false;
            result.pop_back();
        }
        result += c;
        visited[c] = true;
    }
    return result.substr(1);
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
assert(s.size()>=1&&s.size()<=100000);
for(auto &it:s)assert(it>='a'&&it<='z');
cout<<removeDuplicateLetters(s)<<"\n";
}
return 0;}

