/*
BALLSUM - Ball sum
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,k;
cin>>n>>k;
while(n!=-1){
    ll a,b,p,q,t;
    if(n&1){
        a=(n-1)/2;
        b=n;}
    else{
        a=n/2;
    b=n-1;}
    q=a*b;
    t=k>>1;
    p=k*t-t*(t+1);
    ll x=__gcd(p,q);
    p/=x;
    q/=x;
    if(p)
        cout<<p<<"/"<<q<<"\n";
    else
        cout<<"0\n";
cin>>n>>k;}
return 0;}
