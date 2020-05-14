#include<bits/stdc++.h>
using namespace std;
#define max 100000001
vector<int> a(max,1),b;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long

inline int scan(){
   register char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9')
        c=getchar_unlocked();
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}

inline void print(ll b){
	char snum[12];
	int i=0;
	do{
		snum[i++]=b%10+'0';
		b=b/10;
	}while(b);
	i=i-1;
	while (i>=0)
		pc(snum[i--]);
}

int main(){


return 0;
}
