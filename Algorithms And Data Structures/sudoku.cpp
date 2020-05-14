#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005

int a[10][10];

void print(){
    cout<<"\n";
    for(int i = 1; i < 10; ++i)
        for(int j = 1; j < 10; ++j)
            cout<< a[i][j] <<(j == 9? "\n" : " ");
}

bool safe(int x,int y,int z){
    for(int i = 1; i < 10; ++i)
        if(a[i][y] == z || a[x][i] == z)
            return 0;
    if(x%3 == 0)
        x -= 2;
    else
        x = x - x%3 + 1;
    if(y%3 == 0)
        y -= 2;
    else
        y = y - y%3 + 1;
    for(int i = x; i < x + 3; ++i)
        for(int j = y; j < y + 3; ++j)
            if(a[i][j] == z)
                return 0;
    return 1;
}

bool solve(){
    int x = -1, y = -1;
    for(int i = 1; i < 10; ++i){
        for(int j = 1; j < 10; ++j)
        if(!a[i][j]){
            x = i, y = j;
                break;
        }
    if(x != -1)
        break;
    }
    if(x == -1)
        return 1;
    for(int i = 1; i < 10; ++i){
            if(!safe(x,y,i))
                continue;
        a[x][y]=i;
        if(solve())
            return 1;
        else
            a[x][y] = 0;
    }
    return 0;
}


int main(){
sp;
    for(int i = 1; i < 10; ++i)
        for(int j = 1; j < 10; ++j)
            cin>>a[i][j];
    if(solve())
        print();
    else
        cout<<"IMPROPER SUDOKU\n";
return 0;}
