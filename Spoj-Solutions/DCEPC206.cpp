/*
DCEPC206 - Its a Murder!
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans1;
void merge(ll arr[],ll l,ll mid,ll r){
	ll ans=0;
	ll i=l,j=mid+1,k=0;
	ll c[r-l+1];
	while(i<=mid&&j<=r){
		if(arr[i]<arr[j]){

			ans+=arr[i];
			//ans1+=arr[i];

			//cout<<arr[i]<<" "<<ans1<<endl;
			c[k++]=arr[i++];
		}
		else{
			ans1+=ans;
			c[k++]=arr[j++];
		}
	}
	while(i<=mid){
		c[k++]=arr[i++];
	}
	while(j<=r){
		c[k++]=arr[j++];
		ans1+=ans;
	}
	for(i=0;i<k;i++){
		arr[l+i]=c[i];
	}
	//ans1+=ans;
//	cout<<ans1<<endl;
}
void mergesort(ll arr[],ll l,ll r){
	if(l<r){
		ll mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
ll arr[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		ans1=0;
		ll n;
		cin>>n;
		ll i;
		for(i=0;i<n;i++)
		cin>>arr[i];
		mergesort(arr,0,n-1);
		cout<<ans1<<endl;

	}

}
