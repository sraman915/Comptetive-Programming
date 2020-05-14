/*
ONEZERO - Ones and zeros
https://www.spoj.com/problems/ONEZERO/
ONEZERO - Ones and zeros

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<string,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 100005


int main(){
sp;
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    queue<pi> q;
    if(n==1){
        cout<<"1\n";
        continue;
    }
    q.push({"1",1});
    string s;
    int x;
    while(!q.empty()){
        s=q.front().f;
        x=q.front().s;
        q.pop();
        if(x==0){
            cout<<s<<"\n";
            break;
        }
        int x1,x2;
        x1=(x*10)%n;
        x2=(x1+1)%n;
        string s1=s;
        s.pb('0');
        s1.pb('1');
        q.push({s,x1});
        q.push({s1,x2});
    }
}
return 0;}
