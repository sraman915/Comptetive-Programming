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

const int MAX_CHAR = 26;
bool adjSign(string &s, int i)
{
    if (i == 0)
        return true;
    if (s[i - 1] == '-')
        return false;
    return true;
};

void eval(string &s, vector<int>& v, bool add) {
    stack<bool> stk;
    stk.push(true);

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '+' || s[i] == '-') {
            i++;
            continue;
        }
        if (s[i] == '(') {
            if (adjSign(s, i))
                stk.push(stk.top());
            else
                stk.push(!stk.top());
        }
        else if (s[i] == ')')
            stk.pop();

        else {
            if (stk.top())
                v[s[i] - 'a'] += (adjSign(s, i) ? add ? 1 : -1 :
                                                  add ? -1 : 1);
            else
                v[s[i] - 'a'] += (adjSign(s, i) ? add ? -1 : 1 :
                                                  add ? 1 : -1);
        }
        i++;
    }
};

bool areSame(string &expr1, string &expr2) {
    vector<int> v(MAX_CHAR, 0);
    eval(expr1, v, true);
    eval(expr2, v, false);
    for (int i = 0; i < MAX_CHAR; i++)
        if (v[i] != 0)
            return false;

    return true;
}

int32_t main(){
sp;
freopen("input1.txt","r",stdin);
freopen("output1.txt","w",stdout);
int t;
cin>>t;
while(t--){
string a,b;
cin>>a>>b;
if(areSame(a,b))cout<<"1\n";
else cout<<"0\n";
}
return 0;}

