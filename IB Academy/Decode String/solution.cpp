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

string decodeString(string s) {
    assert(s.size()<=100000);
    string res="";
    int number = 0;
    stack<int> numstack;
    stack<string> charstack;
    string characterCopy ="";
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>='0' && s[i]<='9')
                number = number*10 +(s[i]-'0');
        else if(s[i] == '['){
                numstack.push(number);
                number =0;
                charstack.push(characterCopy);
                characterCopy = "";
        }
        else if(s[i] == ']'){
                string temp = "";
                int n = numstack.top();
                numstack.pop();
                for(int i=0;i<n;i++)
                    temp+=characterCopy;
                characterCopy = charstack.top()+temp;
                charstack.pop();
            }
        else
            characterCopy+=s[i];
        }
    assert(characterCopy.size()<=200000);
    return characterCopy;
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
    string ans=decodeString(s);
    cout<<ans<<"\n";
}
return 0;}
