#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007

int gcd(int a,int b)
{
	if(a>b)
		return gcd(b,a);
	else if(a==0 && a==b)
		return 0;
	else if(a==0)
		return b;
	else
		return __gcd(a,b);
}

void solve(){
int n;
  cin>>n;
  assert(n>=1&&n<=100000);
  int a[n+1];
  int i,flag,ps;
  memset(a,0,sizeof a);
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        assert(a[i]>=0&&a[i]<=1000000000);
	        }
	    sort(a,a+n);
	    if (n<3){
	        for (i=n-1;i>=0;i--)
	             cout<<a[i]<<" ";
	        cout<<"\n";
	        return;
	    }
	    else{
	        flag=0;
	        for (i=2;i<n;i++){
	            if(a[i]!=a[i-1]+gcd(a[i-1],a[i-2])){
	                flag=1;
	                ps=i;
	                break;
	            }
	        }
	        if (flag==0){
	            if (a[1]==a[0]+gcd(a[0],a[n-1])){
	                cout<<a[n-1]<<" ";
	                for(i=0;i<n-1;i++)
	                    cout<<a[i]<<" ";
	                cout<<"\n";
	                }
	            else{
	                for(i=0;i<n;i++)
	                    cout<<a[i]<<" ";
	                cout<<"\n";
	                }
	                return;
	            }
	        else{
	            if (a[1]==a[0]+gcd(a[ps],a[0])){
	                flag=0;
	                for(i=n-1;i>ps+2;i--){
	                    if(a[i]!=a[i-1]+gcd(a[i-1],a[i-2])){
	                       flag=1;
	                       break;
	                      }
	                    }
	               if (flag==0 and ps<n-1){
	                   if (a[ps+1]!=a[ps-1]+gcd(a[ps-1],a[ps-2]))
	                       flag=1;
	               }
	               if (flag==0 and ps<n-2){
	                   if (a[ps+2]!=a[ps+1]+gcd(a[ps-1],a[ps+1]))
	                       flag=1;
	               }
	             if (flag==0){
	                 cout<<a[ps]<<" ";
	              for(i=0;i<n;i++)
	                  if(i!=ps)
	                     cout<<a[i]<<" ";
	              cout<<"\n";
	              return;
	             }
	            }
	          }
	      }
	    if (flag==1)
	        cout<<"-1 "<<"\n";
}

int main() {
	fastIO;
	freopen("input3.txt","r",stdin);
	freopen("output3.txt","w",stdout);
	int n,i,j;
	int t,q;
	cin>>t;
    while(t--){
    	solve();
    }
	return 0;
}
