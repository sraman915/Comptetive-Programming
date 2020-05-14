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


mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
random_device rd;

uniform_real_distribution<double> r1(1.0,20.0);
uniform_int_distribution<int> r2(1,1000);
normal_distribution<double> r3(1.0,20.0);
exponential_distribution<double> r4(5);

int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}

string tostring(int x){
string s;
while(x){
s.push_back(x%10+'0');
x/=10;
}
reverse(s.begin(),s.end());
return s;
}

int32_t main(){
sp;
srand(chrono::high_resolution_clock::now().time_since_epoch().count());
freopen("input3.txt","w",stdout);
    int t=100;
    cout<<t<<"\n";
    for(int ii=1; ii<=t; ++ii){
        vector<string> v;
        vector<string> v1;
        int n=10000;
        for(int i=0; i<n; ++i){
        v1.push_back(tostring(5+rng(5)));
        int m=2+rng(8);
        string s;
        for(int j=0; j<m; ++j)
            s.push_back(rng(26)+'a');
        v.push_back(s);
        }
        random_shuffle(v.begin(),v.end());
        random_shuffle(v1.begin(),v1.end());
        stack<char> s1;
        string input;
        int z=500+rng(500);
        for(int i=0;i<z; ++i){
            input+=v1.back();
            v1.pop_back();
            int yy=rng(2);
            if(yy==0){
                input.push_back('[');
                input+=v.back();
                v.pop_back();
                input.push_back(']');
            }
            else{
                input.push_back('[');
                input+=v.back();
                v.pop_back();
                input+=v1.back();
                v1.pop_back();
                input.push_back('[');
                input+=v.back();
                v.pop_back();
                input.push_back(']');
                input.push_back(']');
            }
        }
        cout<<input<<"\n";
}
return 0;
}
