/*
CRAN02 - Roommate Agreement
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int main(){
    sp;
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    unordered_map<ll,ll> m;
    m.reserve(n+10);
    ll x=0;
    ll y=0;
    for(int i=0; i<n; ++i){
        cin>>x;
        y+=x;
        if(m.find(y)==m.end())
            m[y]=1;
        else
        m[y]++;
    }
    ll ans=0;
    unordered_map<ll,ll>::iterator it;
    for(it=m.begin(); it!=m.end(); ++it){
        x=it->first;
        y=it->second;
        if(x)
            ans+=((y*(y-1))>>1LL);
        else ans+=((y*(y+1))>>1LL);
    }
    cout<<ans<<"\n";
}
return 0;}
