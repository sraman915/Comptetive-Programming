/*
EIGHTS - Triple Fat Ladies
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main(){
ll a=1LL*192,d=1LL*250;
int t;
scanf("%d",&t);
while(t--){
    ll k;
    cin>>k;
    ll ans=a+k*d-d;
    printf("%llu\n",ans);
}
return 0;}
