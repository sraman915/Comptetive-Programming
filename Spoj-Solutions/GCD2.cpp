/*
GCD2-GCD2
SOLUTION BY-RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
if(b==0)
    return a;
    gcd(b,a%b);
}
int main(){
int t;
scanf("%d",&t);
while(t--){
    int a;
    scanf("%d",&a);
    string s;
    cin>>s;
    int b=0;
    if(a){
int l=s.size();
for(int i=0; i<l; ++i){
    b=b*10+s[i]-'0';
    b=b%a;
}
int ans=gcd(a,b);
printf("%d\n",ans);
}
else
    cout<<s<<endl;}
return 0;
}
