#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
ll a[N], x[N], y[N], dist[N];
int closestPair(vector<pair<ll, ll> > v){
    int n = v.size();
    sort(v.begin(), v.end());
    set<pair<ll, ll> > s;
    ll best_dist = LLONG_MAX;
    int j = 0;
    for(int i = 0; i < n; i++){
        ll d = ceil(sqrtl(best_dist));
        while(v[i].first - v[j].first >= best_dist){
            s.erase({v[j].second, v[j].first});
            j++;
        }
        auto it1 = s.lower_bound({v[i].second - d, v[i].first});
        auto it2 = s.upper_bound({v[i].second + d, v[i].first});
        for(auto it = it1; it != it2; it++){
            ll dx = v[i].first - (it -> second);
            ll dy = v[i].second - (it -> first);
            best_dist = min(best_dist, dx * dx + dy * dy);
        }
        s.insert({v[i].second, v[i].first});
    }
    return best_dist;
}
int main(){
    int n;
    cin >> n;
    vector<pair<ll, ll> > v;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> y[i];
        if(i != 1)
            dist[i] = dist[i - 1] + ((abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1])) * ((i & 1) ? -1 : 1));
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
        v.push_back({dist[i], a[i]});
    }
    cout << closestPair(v);
return 0;
}
