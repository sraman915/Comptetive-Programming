/*
INVCNT - Inversion Count
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans1=0;
ll merge(int a[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    ll ans=0;
    for(int i=0; i<n1; i++)
        L[i]=a[l+i];
    for(int i=0; i<n2; i++)
        R[i]=a[m+1+i];
    int i,j,k;
    i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i++];
        }
        else{
            a[k]=R[j++];
            ans+=(ll)(n1-i);
        }
        ++k;
    }
while(i<n1){
    a[k]=L[i];
    i++;
    k++;}
while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
    return ans;
}
ll mergesort(int a[],int l,int r){
    if(l>=r)
        return 0;
        int m=(l+r)/2;
    ll p1=mergesort(a,l,m);
ll p2=mergesort(a,m+1,r);
ll p3=merge(a,l,m,r);
return (p1+p2+p3);
}
int main(){
int t;
scanf("%d",&t);
while(t--){
    int n;
    ans1=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; ++i)
        scanf("%d",a+i);
       ans1= mergesort(a,0,n-1);
    printf("%lld\n",ans1);
}

return 0;
}
