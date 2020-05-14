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



void rec(int idx, string& s, string curr_str, int off_left, int off_right, set<string>& res_set, int balance) {
    if (idx == s.length()) {
        if (off_left == 0 && off_right == 0) {
            res_set.insert(curr_str);
            }
        }
    else if(balance >= 0) {
        if (s[idx] == '(' && off_left > 0) {
            rec(idx+1, s, curr_str, off_left-1, off_right, res_set, balance);
            }
        if (s[idx] == ')' && off_right > 0) {
            rec(idx+1, s, curr_str, off_left, off_right-1, res_set, balance);
            }
        int diff = 0;
        if (s[idx] == ')') {
            diff = -1;
        }
        if (s[idx] == '(') {
            diff = 1;
        }
        rec(idx+1, s, curr_str + s[idx], off_left, off_right, res_set, balance + diff);
    }
}

void set_off_counts(int& off_left, int& off_right, string &s) {
    for(char c : s) {
        if (c == '(')
            off_left++;
        if (c == ')') {
            if (off_left > 0) {
                off_left--;
            }
            else{
                off_right++;
            }
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    int off_left = 0, off_right = 0;
    set_off_counts(off_left, off_right, s);
    set<string> res_set;
    rec(0, s, "", off_left, off_right, res_set, 0);
    vector<string> res;
    for (string val : res_set)
        res.push_back(val);
        return res;
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
    int n=s.size();
    assert(n>=1&&n<=200000);
    vector<string> ans=removeInvalidParentheses(s);
    for(auto &it:ans)
        cout<<it<<" ";
    cout<<"\n";
}
return 0;}
