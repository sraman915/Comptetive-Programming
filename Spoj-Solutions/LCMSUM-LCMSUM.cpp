/*
LCMSUM- LCM SUM
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long ans[1000005];
void pre(){
for(long long i=1; i<=1000004; ++i) a[i]=i;
for(long long i=2; i<=1000004; ++i){
    if(a[i]==i){
        for(long long j=i; j<=1000004; j+=i){
            a[j]/=i;
            a[j]*=(i-1);
        }
    }
}
for(long long i=1; i<1000005; ++i){
        for(long long j=i; j<1000005; j+=i){
         ans[j]+=(i*a[i]);
        }
}
}
int main(){
pre();
int t;
scanf("%d",&t);
while(t--){
    long long n;
    scanf("%lld",&n);
    long long aa=ans[n]+1;
    aa=aa*n;
    aa/=2;
    printf("%lld\n",aa);
}
return 0;
}
