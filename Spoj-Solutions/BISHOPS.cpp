/*
BISHOPS - BISHOPS
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int l=s.size();
        int c=0;
        int p=0;
        int k=s[0]-'0';
        if(k==1&&l==1)
            cout<<1<<endl;
        else{
        reverse(s.begin(),s.end());
        for(int i=0; i<l; ++i){
            p=s[i]-'0';
            p=2*p;
            if(c)
                p+=c;
            c=p/10;
            p=p%10;
            s[i]=p+'0';
        }
        if(c)
            s=s+"1";
        int n=s.size();
        int b=0;
        p=s[0]-'0';
        p=p-2;
        if(p<0)
        {
            b=1;
            p+=10;
        }
        s[0]=p+'0';
        int i=1;
        while(b&&i<n){
            p=s[i]-'0';
            p-=1;
            if(p<0)
                p+=10;
            else b=0;
            s[i]=p+'0';
            ++i;
        }
        reverse(s.begin(),s.end());
         n=s.size();
        i=0;
        while(s[i]=='0')
            ++i;
        while(i<n)
        cout<<s[i++];
    cout<<endl;}}
return 0;
}
