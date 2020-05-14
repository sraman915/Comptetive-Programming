/*
EXPEDI - Expedition
SOLUTION BY RAMAN SHARMA
*/
#include<bits/stdc++.h>
using namespace std;
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

bool comp(pair<int,int> a,pair<int,int> b){
if(a.first==b.first)
    return a.second>b.second;
return a.first<b.first;
}

int main(){
sp;
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    pair<int,int> a[n];
    for(int i=0; i<n; ++i) cin>>a[i].first>>a[i].second;
    int d,f;
    cin>>d>>f;
    for(int i=0; i<n; ++i)
        a[i].first=d-a[i].first;
    sort(a,a+n,comp);
    priority_queue<int> q;
    if(f>=d){
        cout<<"0\n";
        continue;
    }
    int st=0,y=1;
    int i=0;
    while(f<d){
        for(; i<n; ++i){
            if(a[i].first<=f)
                q.push(a[i].second);
            else break;
        }
        if(f>=d)
            break;
        if(q.empty()){
            y=0;
            break;
        }
        f+=q.top();
        ++st;
        q.pop();
    }
    if(!y)
        cout<<"-1\n";
    else cout<<st<<"\n";
}
return 0;}

