/*
DCEPC11B-BORING FACTORIALS
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
long long modexp(long long x,long long y,long long m){
long long result=1;
while(y){
        if(y&1)
    result=(result*x)%m;
    x=((x%m)*(x%m))%m;
    y=y>>1;
}
return result;
}

int main(){
int n,t,p;
scanf("%d",&t);
while(t--){
    long long n,p;
    scanf("%lld%lld",&n,&p);
    if(n>=p)
        printf("0\n");
    else{
        long long k=1;
for(long long i=n+1; i<p; ++i)
    k=(k*i)%p;

long long z=modexp(k,p-2,p);
z*=-1;
z=(z+p)%p;
printf("%lld\n",z);

    }
}
    return 0;
}
