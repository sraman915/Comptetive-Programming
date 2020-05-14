#include <bits/stdc++.h>
#define mod 1000000007
#define mxn 100000
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    int coins[8]= {1,2,5,10,20,50,100,200};
    int ways[mxn+1] = {0};
	ways[0] = 1LL;
	for(int i=0; i<8; i++){
	    for(int j=coins[i]; j<mxn; j++)
            ways[j] =((ways[j])+(ways[j-coins[i]]))%mod;
        }
    while(t--){
        int n;
        cin>>n;
        cout<<(ways[n])%mod<<endl;
    }
return 0;
}
