/*
AMR11E - DISTINCT PRIMES
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define si(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define pi(a) printf("%d",a)
#define pll(a) printf("%lld",a)
#define nl printf("\n")
vector<int> a(1000005,1),b(1000005,0);
vector<int> v;
void pre(){
a[0]=a[1]=0;
for(int i=2; i*i<=1000005; ++i){
        if(a[i]){
    for(int j=i+i; j<1000005; j+=i){
        a[j]=0;
        b[j]+=1;
    }}
}
for(int j=30; j<1000005; ++j){
    if(b[j]>=3)
        v.push_back(j);
    if(v.size()>=1000)
        break;
}
}
int main(){
int t;
si(t);
pre();
while(t--){
        int n;
    si(n);
    n-=1;
    pi(v[n]);
    nl;
}
return 0;}
