#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mp make_pair
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
string s;
int n;
void rec(string p,int i,int l){
    //if(!k) return;
  if(i==l){
    cout<<p<<"\n";
    return;
  }
  for(int j=i; j<l; ++j){
    swap(p[i],p[j]);
    rec(p,i+1,l);
  }
}

int main(){
sp;
    cin>>n;
    s=string(n,' ');
    for(int i=0; i<n; ++i)
        s[i]=i+'A';
    rec(s,0,n);
return 0;}
