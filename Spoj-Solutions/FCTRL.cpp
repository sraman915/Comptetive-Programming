/*
FCTRL-FACTORIAL
SOLUTION BY RAMAN SHARMA
*/
#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
int main()
{int t;
scanf("%d",&t);
while(t--){
long n;
scanf("%ld",&n);
long ans=0;
while(n){
    n/=5;
    ans+=n;
}
printf("%ld\n",ans);
}
 return 0;
}
