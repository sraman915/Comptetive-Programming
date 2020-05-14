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


//x(n+1)=x(n)-func(x)/derivative(func(x));
double a,b,c;

double f(double x){
return (a*x+b*sin(x)-c);
}

double d(double x){
return (a+b*cos(x));
}

int32_t main(){
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
    return 0;
}

