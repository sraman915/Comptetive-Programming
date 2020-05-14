/*
SUMFOUR - 4 values whose sum is 0
SOLUTION BY RAMAN SHARMA
*/
include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

int n;
scanf("%d",&n);
ll a[n],b[n],c[n],d[n];
ll A[n*n],B[n*n];
for(int i=0; i<n; ++i)
scanf("%ld%ld%ld%ld",a+i,b+i,c+i,d+i);
unordered_map<ll,ll> s;
s.reserve(n*n);
int p=0;
for(int i=0; i<n; ++i)
for(int j=0; j<n; ++j)
    A[p++]=a[i]+b[j];
for(int i=0; i<n; ++i)
for(int j=0; j<n; ++j)
if(s.find(c[i]+d[j])==s.end())
    s[c[i]+d[j]]=1;
else s[c[i]+d[j]]+=1;
ll y=0;
for(int i=0; i<n*n; ++i){
    ll temp=-A[i];
    if(s.find(temp)!=s.end())
        y+=s[temp];
}
cout<<y;
return 0;}
