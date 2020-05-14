#include<bits/stdc++.h>
using namespace std;


class lfu{
public:
    vector<pair<int,int> > v;
    int n;
    unordered_map<int,int> mp;
    lfu(){
        n=0;
        v.clear();
        mp.clear();
    }

    lfu(int x){
        v.resize(x);
        n=0;
        mp.clear();
    }
    void display();
    void addprocess(int x);
    void heapify(int i);
};

void lfu::display(){
    for(int i=0; i<n; ++i)
        cout<<v[i].first<<" ";
    cout<<"\n";
}

void lfu::heapify(int i){
    int l=2*i+1;
    int r=2*i+2;
    int small=i;
    if(l<n&&v[l].second<v[small].second)
        small=l;
    if(r<n&&v[r].second<v[small].second)
        small=r;
    if(small!=i){
        mp[v[small].first]=i;
        mp[v[i].first]=small;
        swap(v[i],v[small]);
        heapify(small);
    }
}

void lfu::addprocess(int x){
    if(mp.find(x)!=mp.end()){
        int i=mp[x];
        v[i].second+=1;
        heapify(i);
        return;
    }
    if(n==v.size()){
        mp.erase(v[0].first);
        v[0]=v[--n];
        heapify(0);
    }
    v[n++]={x,1};
    mp[x]=n-1;
    int i=n-1;
    while(i>0&&v[(i-1)/2].second>v[i].second){
        mp[v[i].first]=(i-1)/2;
        mp[v[(i-1)/2].first]=i;
        swap(v[i],v[(i-1)/2]);
        i=(i-1)/2;
    }
}

int main(){
    int n;
    cin>>n;
    lfu a=lfu(n);
    while(1){
        int x;
        cin>>x;
        a.addprocess(x);
        a.display();
    }
return 0;
}
