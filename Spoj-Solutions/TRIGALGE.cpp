/*
TRIGALGE - Easy Calculation
SOLUTION BY RAMAN SHARMA
*/
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
#define priority_queue pq
#define inf (ll)1e15
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

double a,b,c;

double f(double x){
return (a*x+b*sin(x)-c);
}

double d(double x){
return (a+b*cos(x));
}

int main(){
sp;
int t;
cin>>t;
double ep=0.0000001;
while(t--){
cin>>a>>b>>c;
double x=c/a;
double h=f(x)/d(x);
while(abs(h)>ep){
    x-=h;
    h=f(x)/d(x);
}
cout<<fixed<<setprecision(6)<<x<<"\n";
}
return 0;}

