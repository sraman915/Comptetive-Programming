/*
ABCDEF - ABCDEF
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
int n;
scanf("%d",&n);
ll a[n];
for(int i=0; i<n; ++i) scanf("%ld",a+i);
ll b[n*n*n];
int p=0;
unordered_map<ll,ll> m;
m.reserve(n*n*n+10);
for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
        for(int k=0; k<n; ++k){
            b[p++]=a[i]*a[j]+a[k];
            if(a[i]!=0){
            ll temp=a[i]*(a[j]+a[k]);
            if(m.find(temp)==m.end())
                m[temp]=1;
            else
                m[temp]+=1;
        }}
    }
}
ll ans=0;
for(int i=0; i<n*n*n; ++i){
    ll temp=b[i];
    if(m.find(temp)!=m.end())
        ans+=m[temp];
}
printf("%lld",ans);
return 0;}
