#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int INF = -2e9;

int n, m, p;
int dist[N], cnt[N];
bool inqueue[N];
vector<pair<int, int> > g[N];
vector<int> rg[N];
bool vis[N];

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u] = 1;
	for(auto &it:rg[u])
		dfs(it);
}

bool negativeCycle() //Returns true if there is a negative cycle
{
	queue<int> q;

	for(int i = 1; i <= 1; i++)
	{
		dist[i] = cnt[i] = 0;
		q.push(i), inqueue[i]=true;
	}

	for(int i = 2; i <= n; i++)
		dist[i] = -INF;

	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		inqueue[v]=false;

		for(auto &edge:g[v])
		{
			int to=edge.first;
			int w=edge.second;

			if(dist[v] + w < dist[to])
			{
				dist[to] = dist[v] + w;
				dist[to] = max(dist[to], INF);
				if(!inqueue[to])
				{
					q.push(to);
					inqueue[to]=true;
					cnt[to]++;
					if(cnt[to]>n)
						return true;
				}
			}
		}
	}
	return false;
}

int32_t main()
{
	IOS;
	cin >> n >> m >> p;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, p - w});
		rg[v].push_back(u);
	}
	dfs(n);
	for(int i = 1; i <= n; i++)
	{
		vector<pair<int, int> > v;
		for(auto &it:g[i])
			if(vis[it.first])
				v.push_back(it);
		g[i].clear();
		g[i] = v;
	}
	int check = negativeCycle();
	if(check)
	{
		cout << "-1";
		return 0;
	}
	cout << max(0LL, -dist[n]);
	return 0;
}
