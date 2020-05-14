/*
ODDDIV-ODD NUMBER OF DIVISORS
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1010
vector<ll> g[10000],p;
int l,k;
vector<bool> a(mx,0);
void sieve(){
for(int i=2; i*i<=mx; ++i){
    if(!a[i]){
        for(int j=i*i;j<mx; j+=i)
            a[j]=1;
    }
}
p.push_back(2);
for(ll i=3; i<mx; i+=2){
    if(!a[i])
    p.push_back(i);
}
l=p.size();
}
void pre(){
for(ll i=2; i<100001; ++i){
    ll temp=i,d=1;
    for(ll j=0; j<l; ++j){
        if(p[j]>temp) break;
        if(temp%p[j]) continue;
        int t=0;
        while(temp%p[j]==0){
            ++t;
            temp/=p[j];
        }
        d=d*(2*t+1);
    }
    if(temp>1)
        d*=3;
    if(d<10000)
        g[d].push_back(i*i);
}
}
int main(){
    sieve();
    pre();
int t;
scanf("%d",&t);
while(t--){
    ll low,high;
    scanf("%d%lld%lld",&k,&low,&high);
   cout<<upper_bound(g[k].begin(),g[k].end(),high)-lower_bound(g[k].begin(),g[k].end(),low)<<"\n";
}
return 0;}
