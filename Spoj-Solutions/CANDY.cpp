/*
CANDY - Candy I
SOLUITON BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
scanf("%d",&n);
while(n!=-1){
    int a[n];
    int s=0,y=1;
    for(int i=0; i<n; ++i){
        scanf("%d",a+i);
        s+=a[i];
    }
    if(s%n)
        y=0;
    int moves=0,pos=0,neg=0,don,lon=0,opt=s/n;
    for(int i=0; i<n; ++i){
        if(a[i]==opt) continue;
        if(a[i]>opt){
            don=a[i]-opt;
            if(neg>=don){
            neg-=don;
            don=0;
            }
            else{
                don-=neg;
                neg=0;
                pos+=don;
            }
            moves+=don;
            pos+=don;
        }
        else{
                lon=opt-a[i];
               if(pos>=lon){
                pos-=lon;
                lon=0;
               }
               else{
                lon-=pos;
                pos=0;
                neg+=lon;
               }
               moves+=lon;

        }
    }
    if(y)
    printf("%d\n",abs(moves));
    else
        printf("-1\n");
scanf("%d",&n);
}

return 0;}
