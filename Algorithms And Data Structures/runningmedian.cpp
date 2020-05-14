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

priority_queue<int, vector<int>, greater <int> > min_heap;
priority_queue<int> max_heap;

void add(int a){
    if( max_heap.size() && a >= max_heap.top())
        min_heap.push(a);
    else
        max_heap.push(a);

    if(abs(max_heap.size() - min_heap.size()) > 1){
        if(max_heap.size() > min_heap.size()){
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
        else{
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
    }
}

int get_median(){
    int total = min_heap.size() + max_heap.size();
    int ret;
    if(total%2 == 1){
        if(max_heap.size() > min_heap.size())
            ret = max_heap.top();
        else
            ret = min_heap.top();
    }
    else{
        ret = INT_MAX;
        if(max_heap.empty() == false)
            ret = min(ret,max_heap.top());
        if(min_heap.empty() == false)
            ret =min(ret,min_heap.top());
    }
    return ret;
}

vector<int> runningMedian(vector<int> &a){
    int n=a.size();
    vector<int> ans;


    while(!min_heap.empty())
        min_heap.pop();

    while(!max_heap.empty())
        max_heap.pop();

    for(int i=0;i<n; ++i){
        add(a[i]);
        ans.push_back(get_median());
    }

    return ans;
}


int32_t main(){
sp;

    return 0;
}
