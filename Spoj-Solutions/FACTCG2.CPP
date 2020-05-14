/*
FACTCG2 - Medium Factorization
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
#define mxn 10000001
int a[mxn];
void pre(){
for(int i=2; i*i<=mxn; ++i){
    if(!a[i]){
        for(int j=i*i; j<mxn; j+=i){
            if(!a[j])
            a[j]=i;}
    }
}
a[2]=2;
for(int i=3; i<mxn; i+=2){
    if(!a[i])
        a[i]=i;
}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
ll n;
pre();
while(cin>>n){
        if(n==1){
        cout<<"1\n";
        continue;
        }
       cout<<"1";
    while(n>1){
            cout<<" x ";
        cout<<a[n];
    n/=a[n];
    }
    cout<<"\n";
}
return 0;
}
