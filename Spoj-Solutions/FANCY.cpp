/*
FANCY - FANCY NUMBERS
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll p[34];
void pre(){
p[0]=1;
p[1]=2;
for(int i=2; i<34; ++i)
    p[i]=p[i-1]*2LL;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
pre();
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    int l=s.size();
    ll c=1LL;
    ll ans=1LL;
    for(int i=1; i<l; ++i){
        c=1LL;
        while(s[i]==s[i-1]&&i<l){
            ++i;
            ++c;
        }
        ans*=p[c-1];
    }
    cout<<ans<<"\n";
}
return 0;
}
