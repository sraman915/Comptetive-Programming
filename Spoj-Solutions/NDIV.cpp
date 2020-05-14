/*
NDIV - n-divisors
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int main(){
int a,b,n;
cin>>a>>b>>n;
int d[b-a+10];
memset(d,0,sizeof d);
for(int i=1; i*i<=b; ++i){
    for(int j=((a-1)/i+1)*i; j<=b; j+=i){
        if(j<i*i) continue;
        if(j==i*i) d[j-a]+=1;
        else d[j-a]+=2;
    }
}
int x=0;
for(int i=a; i<=b; ++i){
    if(d[i-a]==n) ++x;
}
cout<<x;
return 0;}
