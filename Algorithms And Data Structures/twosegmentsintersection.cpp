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

struct point{
	int x, y;
	point(){
        x = 0;
        y = 0;
	}
	point(int x, int y){
        this->x = x;
        this->y = y;
	}
};


pair<int, int> intersectingpointoftwosegments(point a, point b, point c, point d){
	int a1 = b.y - a.y;
	int b1 = a.x - b.x;
	int c1 = a1 * a.x  + b1 * a.y;
	int a2 = d.y - c.y;
	int b2 = c.x - d.x;
	int c2 = a2 * c.x + b2 * c.y;
	int determinant = a1 * b2 - a2 * b1;
	if(determinant == 0)
		return {-inf, -inf}; // no intersection
    if((b2 * c1 - b1 * c2) % determinant != 0 || (a1 * c2 - a2 * c1) % determinant != 0)
        return {-inf, -inf};
    int x = (b2 * c1 - b1 * c2)/determinant;
    int y = (a1 * c2 - a2 * c1)/determinant;
    if(x < min(a.x, b.x) || x > max(a.x, b.x)) // no intersection
        return {-inf, -inf};
    if(y < min(a.y, b.y) || y > max(a.y, b.y)) // no intersection
        return {-inf, -inf};
    if(x < min(c.x, d.x) || x > max(c.x, d.x)) // no intersection
        return {-inf, -inf};
    if(y < min(c.y, d.y) || y > max(c.y, d.y)) // no intersection
        return {-inf, -inf};
    return {x, y};
}

int32_t main(){
sp;

    return 0;
}
