/*
AE00 - RECTANGLES
SOLUTION BY RAMAN SHARMA
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    int ans=0;
    int x=sqrt(n);
    for(int i=1; i<=x; i++){
        ans+=n/i-(i-1);
    }
    printf("%d",ans);
    return 0;
}
