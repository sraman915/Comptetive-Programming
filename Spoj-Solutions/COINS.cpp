/*
COINS - Bytelandian gold coins
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long
map<ll,ll> m;
ll rec(ll n){
if(n==0)
    return 0;
if(m.find(n)!=m.end())
    return m[n];
ll x=rec(n/2)+rec(n/3)+rec(n/4);
if(x>n)
    m[n]=x;
else
    m[n]=n;
    return m[n];
}
int main(){
//sp;
ll n;
while(cin>>n){
cout<<rec(n)<<"\n";
}
return 0;}
