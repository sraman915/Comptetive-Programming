/*
ADDREV - ADDING REVERSED NUMBERS
SOLUTION BY RAMAN SHARMA
*/
#include <bits/stdc++.h>
using namespace std;
int rev(int n){
	int s=0;
	while(n){
		s=s*10+n%10;
		n/=10;
	}
	return s;}
int main() {
	int n;
	scanf("%d",&n);
	while(n--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=rev(x);
		y=rev(y);
		int z=x+y;
		z=rev(z);
		printf("%d\n",z);
	}
	return 0;
}
