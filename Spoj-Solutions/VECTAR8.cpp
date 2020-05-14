/*
VECTAR8 - Primal Fear
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 1000005
vector<int> a(mxn),b(mxn);
int md[9];
void sieve(){
a[0]=a[1]=1;
for(int i=4; i<mxn; i+=2)
    a[i]=1;
for(int i=3; i*i<=mxn; i+=2){
    if(!a[i]){
        for(int j=i*i; j<mxn; j+=i)
            a[j]=1;
    }
}
md[0]=1;
for(int i=1; i<9; ++i)
    md[i]=10*md[i-1];
}
bool check(int n){
int d=0;
int t=n;
while(t){
    ++d;
    t/=10;
}
int m=md[d-1];
while(n){
    if(a[n])
        return 0;
    n=n%m;
    m/=10;
}
return 1;
}
bool zcheck(int n){
    int m;
while(n){
m=n%10;
if(!m)
    return 0;
n/=10;
}
return 1;
}
void pre(){
sieve();

b[0]=b[1]==0;
b[2]=1;
b[3]=2;
b[5]=3;
b[4]=2;
for(int i=6; i<mxn; ++i){
    b[i]=b[i-1];
    if(!a[i]&&zcheck(i)){
    if(check(i))
        b[i]+=1;
    }
}
}

int main(){
    pre();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<b[n]<<"\n";
    }

return 0;
}
