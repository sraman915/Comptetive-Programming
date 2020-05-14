#include<bits/stdc++.h>

using namespace std;

class LRUcache{
    list<int> dq;
    unordered_map<int,list<int>::iterator> mp;
    int cachesize;

    public:
    LRUcache(int);
    void Processentry(int);
    void display();
};

LRUcache::LRUcache(int n){
    cachesize=n;
}

void LRUcache::Processentry(int x){
    if(mp.find(x)==mp.end()){
        if(dq.size()==cachesize){
            mp.erase(dq.back());
            dq.pop_back();
        }
    }
    else
        dq.erase(mp[x]);
    dq.push_front(x);
    mp[x]=dq.begin();
}

void LRUcache::display(){
    for(auto &it:dq)
        cout<<it<<" ";
    cout<<"\n";
}

int main(){
    int n,m;
    cout<<"ENTER THE NUMBER OF PROCESS AND SIZE OF CACHE\n";
    cin>>n>>m;
    LRUcache A(m);
    int x;
    while(n--){
        cin>>x;
        A.Processentry(x);
        A.display();
    }
return 0;}
