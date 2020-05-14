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

void computeLPSArray(string str, int M, int lps[])
{
    int len = 0;
    int i;

    lps[0] = 0;
    i = 1;
    while (i < M)
    {
       if (str[i] == str[len])
       {
           len++;
           lps[i] = len;
           i++;
       }
       else
       {
          if (len != 0)
          {
             len = lps[len-1];

          }
          else
          {
             lps[i] = 0;
             i++;
          }
       }
    }
}

bool isRepeat(string &s)
{
    int n = s.size();
    int lps[n];
    computeLPSArray(s, n, lps);
    int len = lps[n-1];
    return (len > 0 && n%(n-len) == 0)? true: false;
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
if(isRepeat(s))cout<<"1\n";
else cout<<"0\n";
}

return 0;}

