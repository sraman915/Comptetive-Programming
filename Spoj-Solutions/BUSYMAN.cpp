/*
BUSYMAN - I AM VERY BUSY
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define mp make_pair
#define pi pair<int,int>

bool comp(pi a,pi b){
if(a.second==b.second)
    return a.first<b.first;
return a.second<b.second;
}
int main(){
sp;
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    pi a[n];
    for(int i=0; i<n; ++i)
        cin>>a[i].first>>a[i].second;

        sort(a,a+n,comp);
        int ans=1;
        int st=a[0].first,en=a[0].second;
        for(int i=1; i<n; ++i){
            if(a[i].first>=en){
                ++ans;
                en=a[i].second;
            }
        }
    cout<<ans<<"\n";
}
return 0;}
