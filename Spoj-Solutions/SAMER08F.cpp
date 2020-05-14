/*
SAMER08F - Feynman
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long
int main(){
    sp;
ll n;
while(1){
        cin>>n;
    if(!n) break;
n=(n*(n+1)*(2*n+1))/6;
cout<<n<<"\n";
}
return 0;}
