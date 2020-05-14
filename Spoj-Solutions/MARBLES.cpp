/*
MARBLES - Marbles
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

ll ncr(ll n,ll r){
    if(r>n) return 0LL;
    if(n==r)
        return 1LL;
ll ans=1;
if(r>n-r)
    r=n-r;

for(ll i=0; i<r; ++i){
    ans*=(n-i);
    ans/=(i+1LL);
}
return ans;
}
int main(){
    sp;
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        cout<<ncr(n-1,k-1)<<"\n";

    }

return 0;
}
