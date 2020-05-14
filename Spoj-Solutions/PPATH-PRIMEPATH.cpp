/*
PRIME PATH-PPATH
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[11000],check(100001,0),sieve(100001,0),prime,level(100001);
int w=0;
void sieve1(){
int i,j;
for(i=2;i*i<=100000;i++){
    if(sieve[i]==0){
        for(j=i*i;j<=100000;j+=i){
            sieve[j]=1;
        }
    }
}
//cout<<"reachinsieve\n";
}
void f(){
int i,j;
for(i=1000;i<=10000;i++){
        graph[i].clear();
    if(!sieve[i]){
        prime.push_back(i);
}
}
//for(i=0;i<prime.size();i++)
    //cout<<prime[i]<<" ";
//cout<<prime.size()<<endl;
int count1,p,q;
for(i=0;i<prime.size();i++){
    for(j=i+1;j<prime.size();j++){
         p=prime[i];
         q=prime[j];
       //cout<<p<<" "<<q<<endl;
        int s1[5];
        int s2[5];
        int k=0,l=0;
        while(p>0){
            s1[k]=p%10;
            p/=10;
            k++;
        }
        while(q>0){
            s2[l]=q%10;
            q/=10;
            l++;
        }
         count1=0;
        for(int k=0;k<4;k++){
            //cout<<s1[k]<<" "<<s2[k]<<endl;
                if(s1[k]!=s2[k]){
                    count1++;
                }}
                p=prime[i];
                q=prime[j];
                //cout<<"a"<<" ";
                if(count1==1){
                    //cout<<p<<" "<<q<<" ";
                    graph[p].push_back(q);
                }
        /*if(count1==1&&p>1000&&p<10000&&q>1000&&q<10000){
              //  cout<<"a"<<" ";
              w++;
            graph[p].push_back(q);
            graph[q].push_back(j);
        }
    }*/
  //  for(int k=0;k<graph[prime[i]].size();k++)
    //cout<<graph[prime[i]][k]<<" ";}
}}
//cout<<"Dsfs"<<endl;
}


void bfs(int a){
queue<int>qu;
qu.push(a);
check[a]=1;
while(!qu.empty()){

    int p=qu.front();
    qu.pop();
    check[p]=1;
    int y=p;
    int arr1[4];
    int r=3;
    while(y>0){
        arr1[r--]=y%10;
        y/=10;
    }
    int count1;
    for(int i=0;i<prime.size();i++){
        int q=prime[i];
        int q1=q;
        int l=3;
        int arr[4];
        while(q>0){
            arr[l--]=q%10;
            q=q/10;
        }
         count1=0;
        for(l=0;l<=3;l++){
            if(arr1[l]!=arr[l])
                count1++;
        }
        if(count1==1&&check[q1]==0){
            qu.push(q1);
            check[q1]=1;
            level[q1]=level[p]+1;
        }
    }
}
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
prime.clear();
sieve1();
    f();
    int t;
cin>>t;
//for(int i=0;i<prime.size();i++)
  //      cout<<prime[i]<<" ";
while(t--){
    for(int i=0;i<100000;i++){
        check[i]=0;
    }
    int n,m;
    cin>>n>>m;
    level[n]=0;
    bfs(n);
    cout<<level[m]<<endl;
}
}
