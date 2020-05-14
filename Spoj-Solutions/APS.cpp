/*
APS - AMAZING PRIME SEQUENCE
SOLUTION BY RAMAN SHARMA
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> a(10000001,0);
void pre(){
    a[0]=0;
    a[1]=0;
for(int i=2; i*i<=10000001; ++i)
    {
        if(!a[i]){
            for(int j=i*i; j<=10000000; j+=i){
                if(!a[j])
                    a[j]=i;}}}
   for(int i=0; i<10000001; ++i){
    if(!a[i])
        a[i]=i;}
}
int main(){
int t;
scanf("%d",&t);
pre();
while(t--){
    int n;
    scanf("%d",&n);
    unsigned long long x=0,y=0;
    int i=2;
    while(i<=n){
        y=x+(long long)a[i];
                x=y;
        ++i;}
    printf("%llu\n",y);
}
 return 0;
}
