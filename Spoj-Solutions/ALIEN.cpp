/*
ALIEN - Aliens at the train
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long

int main(){
sp;
int t;
cin>>t;
while(t--){
    int n,b;
    cin>>n>>b;
    int a[n];
    for(int i=0; i<n; ++i) cin>>a[i];
    int i=0,j=0,p=0,ss=100000000;
    int x=0,s=0;
    while(i<=j&&j<n){
        if(s+a[j]<=b&&j<n){
            s+=a[j];
            ++x;
            ++j;
        }
        else{
            s-=a[i];
            ++i;
            --x;
        }
     if(x>p){
        ss=s;
        p=x;
     }
     else if(x==p&&ss>s){
        ss=s;
        p=x;
     }
    }
    cout<<ss<<" "<<p<<"\n";
}

return 0;}
