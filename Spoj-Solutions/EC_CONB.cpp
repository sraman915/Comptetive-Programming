/*
EC_CONB - Even Numbers
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
int a[25];
void pre(){
a[0]=1;
for(int i=1; i<25; ++i)
    a[i]=2*a[i-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin>>n;
pre();
int x;
for(int i=0; i<n; ++i){
    cin>>x;
    if(x&1){
        cout<<x<<"\n";
        continue;
    }
    int y=0;
    int m=floor(double(log2(x)));
    for(int i=m; i>=0; --i){
        if((x&(1<<i)))
          y+=a[m-i];
    }
    cout<<y<<"\n";
}

return 0;}
