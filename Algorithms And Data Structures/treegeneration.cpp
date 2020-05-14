
#include<bits/stdc++.h>
#define fi ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const int sz = (int)1e5 + 10;
int n, q, v1, v2, val[ sz ], node, type;
int par[sz], ssz[sz];
set<int>s;

int root( int x ) {
    int x1 = x;
    while( par[x] != x ) {
        x = par[x];
    }
    return par[x1] = x;
}

void unite( int u, int v ) {
    u = root(u);
    v = root(v);
    if( ssz[v] > ssz[u] )
        swap(u,v);
    ssz[u] += ssz[v];
    par[v] = u;
    s.insert(u);
}

int main() {
    fi;
    srand(time(NULL));
    freopen("case.txt","w",stdout);

    //N nodes
    n = 5;
    cout<<n<<"\n";

    set<int>::iterator it;

    for( int i = 1; i <= n; i++ ) {
        par[i] = i;
        ssz[i] = 1;
        s.insert(i);
    }
    int edges = n-1;

    //Edges
    while( edges ) {
        int sz1 = s.size();
        it = s.begin();
        advance(it,rand()%sz1);
        v1 = (*it);
        it = s.begin();
        advance(it,rand()%sz1);
        v2 = (*it);

        // edge between v1 and v2
        if( root(v1) != root(v2) ) {
            s.erase(v1);
            s.erase(v2);
            cout<<v1<<" "<<v2<<"\n";
            unite(v1,v2);
            edges--;
        }

    }

    for( int i = 1; i <= n; i++ ) {
        //cin>>val[i];
        if( i%2 == 0 )
            val[i] = ((rand()%10000)+1)*51200;
        else
            val[i] = ((rand()%10000)+1)*62500;
        if( i == n )
            cout<<val[i]<<"\n";
        else
            cout<<val[i]<<" ";
    }

    //cin>>q;
    q = 5;
    cout<<q<<"\n";
    while(q--) {
        type = rand()%2;
        node = (rand()%n) + 1;
        cout<<type<<" "<<node<<"\n";
        //cin>>type>>node;

    }
    return 0;
}
