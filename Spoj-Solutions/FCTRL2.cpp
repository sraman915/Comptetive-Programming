/*
FCTRL2 - SMALL FACTORIALS
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
            int n;
cin>>n;
int carry=0,k=0;
vector<int> a(1000,0);
a[0]=1;
for(int i=1; i<=n; i++)
{
    for(int j=0; j<=k; j++)
    {
        a[j]=a[j]*i+carry;
        carry=a[j]/10;
        a[j]=a[j]%10;
    }
    while(carry)
    {
        k++;
        a[k]=carry%10;
        carry/=10;
    }
}
for(int i=k; i>=0; i--)
{
    cout<<a[i];
}
cout<<"\n";
    }
    return 0;
}
