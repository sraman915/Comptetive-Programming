#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
getline(cin,s);
reverse(s.begin(),s.end());
int l=s.size();
for(int i=0; i<l; ++i){
    if(s[i]==' ')continue;
    int x=i,y;
    while(s[i]!=' '&&i<l)++i;
    y=i-1;
    while(x<y)swap(s[x++],s[y--]);
}

cout<<s;
return 0;}
