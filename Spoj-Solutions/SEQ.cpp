/*
SEQ - Recursive Sequence
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define mod (ll)1000000007
#define f first
#define s second
#define inf (ll)1e15
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 100010

int main() {
 sp;
int c;
cin>>c;
while(c--){
    ll k,n;
    cin>>k;
    ll p=1000000000LL;
    ll f1[k];
    for(int i=0; i<k; ++i)
        cin>>f1[i];
    ll t[k][k];
    memset(t,0,sizeof t);
    for(int i=0; i<k; ++i)
        cin>>t[0][i];
    for(int i=1; i<k; ++i)
        t[i][i-1]=1LL;
    ll ans[k][k];
    memset(ans,0,sizeof ans);
    for(int i=0; i<k; ++i)
        ans[i][i]=1LL;
       cin>>n;
       if(n<=k){
              cout<<f1[n-1]%p<<"\n";
              continue;
              }
              n=n-k;
        while(n){
            if(n&1){
                ll c[k][k];
                for(int i=0; i<k; ++i){
                    for(int j=0; j<k; ++j){
                        c[i][j]=0;
                        for(int l=0; l<k; ++l)
                        c[i][j]=(c[i][j]+ans[i][l]*t[l][j])%p;}}
                for(int i=0; i<k; ++i)
                    for(int j=0; j<k; ++j)
                        ans[i][j]=c[i][j];
                            }
            ll c[k][k];
                for(int i=0; i<k; ++i){
                    for(int j=0; j<k; ++j){
                        c[i][j]=0;
                        for(int l=0; l<k; ++l)
                        c[i][j]=(c[i][j]+t[i][l]*t[l][j])%p;}
                }
                for(int i=0; i<k; ++i)
                    for(int j=0; j<k; ++j)
                        t[i][j]=c[i][j];
           n>>=1LL;
        }
        ll an=0LL;
            for(int j=0; j<k; ++j)
                an=(an+ans[0][j]*f1[k-1-j])%p;
    cout<<an<<"\n";
}
return 0;}
