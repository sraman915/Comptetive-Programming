/*
SUBSUMS - Subset Sums
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
int main(){
int n;
ll m1,m2,x;
cin>>n>>m1>>m2;
vector<ll> a,b,c,d;
int n1=n/2;
int n2=n-n/2;
for(int i=0; i<n1; ++i){
    cin>>x;
    a.push_back(x);
}
for(int i=n1; i<n; ++i){
 cin>>x;
    b.push_back(x);
}
int l1=(1<<n1);
int l2=(1<<n2);
for(int i=0; i<l1; ++i){
    ll temp=0;
    for(int j=0; j<n1; ++j){
        if(i&(1<<j))
            temp+=a[j];
    }
    c.push_back(temp);
}
for(int i=0; i<l2; ++i){
    ll temp=0;
    for(int j=0; j<n2; ++j){
        if(i&(1<<j))
            temp+=b[j];
    }
    d.push_back(temp);
}
sort(d.begin(),d.end());
ll ans=0;
for(int i=0; i<l1; ++i){
    ll temp=m1-c[i];
    ll temp1=m2-c[i];
    int x=lower_bound(d.begin(),d.end(),temp)-d.begin();
    int y=upper_bound(d.begin(),d.end(),temp1)-d.begin();
    ans+=(ll)(y-x);
}
cout<<ans;
return 0;}
