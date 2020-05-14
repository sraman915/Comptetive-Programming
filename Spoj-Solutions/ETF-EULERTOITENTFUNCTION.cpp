/*
ETF - EULER TOITENT FUNCTION
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> a(1000001);
void pre(){
for(int i=1; i<1000001; ++i) a[i]=i;
for(int i=2; i<1000001; ++i){
    if(a[i]==i){
        for(int j=i; j<1000001; j+=i){
            a[j]/=i;
            a[j]*=(i-1);
        }
    }
}
}
int main(){
pre();
int t;
scanf("%d",&t);
while(t--){
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n]);
}
return 0;}
