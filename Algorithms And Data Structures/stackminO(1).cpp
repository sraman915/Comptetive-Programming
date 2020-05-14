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

class modifiedstack{
    public:
    stack<int> s;
    int mn;
    modifiedstack(){
        mn=INT_MAX;
        while(!s.empty())
            s.pop();
    }
    void push(int x);
    int pop();
    int minimum();
    bool isempty();
};

int modifiedstack::pop(){
    if(isempty())
        return -1;
    int x=s.top();
    s.pop();
    if(x<mn){
        mn=2*mn-x;
        x=(mn+x)/2;
    }
    return x;
}

void modifiedstack::push(int x){
    if(isempty()){
        s.push(x);
        mn=x;
    }
    else{
        if(x<mn){
            int temp=2*x-mn;
            mn=x;
            x=temp;
        }
        s.push(x);
    }
}

int modifiedstack::minimum(){
    if(isempty())
        return -1;
    return mn;
}

bool modifiedstack::isempty(){
    if(s.size()==0)
        return true;
    return false;
}


int32_t main(){
sp;
    modifiedstack s;
    s.push(10);
    s.push(7);
    s.pop();
    cout<<s.minimum();
    return 0;
}
