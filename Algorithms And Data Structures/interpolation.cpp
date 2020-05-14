#include<bits/stdc++.h>
using namespace std;
int interpolation(int a[],int n,int x){
int l=0,r=n-1;
int pos=0;
while(l<r){
    pos=l+(((double)(r-l)/(a[r]-a[l]))*(x-a[l]));
    if(a[pos]==x)
        return pos;
    if(a[pos]<x)
        l=pos+1;
    else
        r=pos-1;

}
return -1;
}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0; i<n; ++i)
    cin>>a[i];
sort(a,a+n);
cout<<interpolation(a,n,9);
return 0;}
