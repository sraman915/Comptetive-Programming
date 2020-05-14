#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

vector<vector<string> > vv;
bool check(int i,int j,string &p){
while(i<j) if(p[i++]!=p[j--])return 0;
return 1;
}

void sub(int i,int n,string &s,vector<string> &v){
if(i>=n){
    vv.push_back(v);
    return;
}
for(int j=i; j<n; ++j){
    if(check(i,j,s)){
        v.push_back(s.substr(i,j+1-i));
        sub(j+1,n,s,v);
        v.pop_back();
    }
}
}

int main(){
sp;
string s;
cin>>s;
vv.resize(0);
vector<string> v;
sub(0,s.size(),s,v);
for(int i=0; i<vv.size(); ++i){
    for(auto it:vv[i])cout<<it<<" ";
    nl;
}
return 0;}
