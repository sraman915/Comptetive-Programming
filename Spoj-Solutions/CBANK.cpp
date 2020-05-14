/*
CBANK - Charu and Coin Distribution
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
ll inv6;
ll modexp(ll x,ll n){
ll r=1LL;
while(n){
    if(n&1)
        r=(r*x)%mod;
    x=(x*x)%mod;
    n>>=1;
}
return r;
}

ll nc3(ll n){
ll ans=(((n*(n-1))%mod)*(n-2))%mod;
ans=(ans*inv6)%mod;
return ans;
}

int main(){
    sp;
inv6=modexp(6LL,mod-2);
int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    cout<<nc3(n+3LL)<<"\n";
}
return 0;}
