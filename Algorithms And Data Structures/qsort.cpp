#include<bits/stdc++.h>
using namespace std;
void print(int a[],int n){
for(int i=0; i<n; ++i)
    printf("%d ",a[i]);
printf("\n");
}
int parttion(int a[],int l,int r){
int pivot=a[r];
int i=l;
for(int j=l; j<r; j++){
    if(a[j]>=pivot)
    {swap(a[j],a[i]);
    ++i;}
}
swap(a[i],a[r]);
return i;
}
void quicksort(int a[],int l,int r){
if(l<r){
 int pi=parttion(a,l,r);
 quicksort(a,l,pi-1);
 quicksort(a,pi+1,r);
}
}
int main(){
   int n;
   scanf("%d",&n);
   int a[n];
   for(int i=0; i<n; i++)
    scanf("%d",a+i);
    quicksort(a,0,n-1);
    print(a,n);
return 0;
}
