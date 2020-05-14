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


string mul(string a,string b){
    int n1=a.size();
    int n2=b.size();
    vector<int> v(n1+n2,0);
    for(int i=n1-1; i>-1; --i)
    for(int j=n2-1; j>-1; --j)
    v[i+j+1]+=(a[i]-'0')*(b[j]-'0');
    for(int i=n1+n2-1; i>0; --i){
        if(v[i]>9){
            v[i-1]+=v[i]/10;
            v[i]%=10;
        }
    }
    int i=0;
    string res="";
    while(i<n1+n2&&v[i]==0)++i;
    if(i==n1+n2)return "0";
    while(i<n1+n2)
    res+=(v[i++]+'0');
    return res;

}

int main(){
sp;
string x="26",y="26";
cout<<mul(x,y);

return 0;}



