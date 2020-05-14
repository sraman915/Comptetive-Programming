/*
CUBEFR - Cube Free Numbers
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define mxn 1000001
#define inf 10000000
#define mp make_pair
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
vector<int> p(mxn),b(mxn),v;
void sieve(){
p[0]=1;
p[1]=1;
for(int i=4;i<mxn; i+=2)
    p[i]=1;
for(int i=3; i*i<mxn; i+=2){
    if(!p[i]){
        for(int j=i*i; j<mxn; j+=i)
            p[j]=1;}
}
v.push_back(2);
for(int i=3; i<mxn; i+=2){
    if(!p[i])
        v.push_back(i);
        if(i>110) break;
}
int l=v.size();
for(int i=0; i<l; ++i){
        int temp=v[i]*v[i]*v[i];
    for(int j=v[i]*v[i]*v[i]; j<mxn; j+=temp){
        b[j]=-1;
    }
}
int k=1;
for(int i=1; i<mxn; ++i){
    if(b[i]!=-1)
        b[i]=k++;
}
}
int main(){
sp;
sieve();
int t;
cin>>t;
for(int i=1; i<t+1; ++i){
        cout<<"Case "<<i<<": ";
    int n;
cin>>n;
    if(b[n]==-1)
    cout<<"Not Cube Free\n";
    else cout<<b[n]<<"\n";



}
return 0;}
