#include<bits/stdc++.h>
using namespace std;

#define int long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (long long)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 500005

class heap{
    public:
        vector<int> v;
        heap(){
            v.clear();
            v.push_back(0);
        }
        heap(vector<int> &a);
        int heapsize();
        int getleftchild(int index);
        int getrightchild(int index);
        int getparent(int index);
        void displayheap();
        void min_heapify(int index);
        void build_min_heap();
        void insert_into_heap(int x);
        void remove_top_element();
        int top_element();
};

int heap::heapsize(){
    return (int)v.size();
}
heap::heap(vector<int> &a){
    v.clear();
    v.push_back(0);
    for(auto &it:a)
        v.push_back(it);
    build_min_heap();
}

int heap::getleftchild(int index){
    if(index+index<heapsize()&&index>=1)
        return index+index;
    return -1;
}


int heap::getrightchild(int index){
    if(index+index+1<heapsize()&&index>=1)
        return index+index+1;
    return -1;
}

int heap::getparent(int index){
    if(index>1&&index<heapsize())
        return index/2;
    return -1;
}

void heap::displayheap(){
    for(int i=1; i<heapsize(); ++i)
        cout<<v[i]<<" ";
    cout<<"\n";
}

void heap::min_heapify(int index){
    int left=getleftchild(index);
    int right=getrightchild(index);
    int small=index;
    if(left!=-1&&v[left]<v[small])
        small=left;
    if(right!=-1&&v[right]<v[small])
        small=right;
    if(small!=index){
        swap(v[small],v[index]);
        min_heapify(small);

    }
}

void heap::build_min_heap(){
    int n=heapsize();
    for(int i=n/2; i>0; --i)
        min_heapify(i);
}

void heap::insert_into_heap(int x){
    int curr=heapsize();
    v.push_back(x);
    while(curr>1&&v[getparent(curr)]>v[curr]){
        swap(v[getparent(curr)],v[curr]);
        curr=getparent(curr);
    }
}

void heap::remove_top_element(){
    int curr=heapsize();
    if(curr==1)
        return;
    swap(v[1],v[curr-1]);
    v.pop_back();
    min_heapify(1);
}

int heap::top_element(){
    if(heapsize()==1)
        return -1;
    return v[1];
}




int32_t main(){
//sp;
    srand(time(NULL));
    vector<int> a;
    a.push_back(12);
    a.push_back(15);
    a.push_back(19);
    a.push_back(22);
    a.push_back(4);
    heap q(a);
    while(1){
        int x,y;
        cout<<q.top_element()<<"\t";
        q.displayheap();
        cin>>x>>y;
        if(x==1)
            q.insert_into_heap(y);
        else
            q.remove_top_element();
    }
    return 0;
}
