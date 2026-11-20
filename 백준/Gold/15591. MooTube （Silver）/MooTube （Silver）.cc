#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

int n, q;
vector<vector<pii>> adj;
vector<pii> query;

void input()
{
  cin >> n >> q;
  adj.resize(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }
  query.resize(q);
  for (auto &i : query)
  {
    cin >> i.first >> i.second;
  }
}

int bfs(int k, int v)
{
  vector<int> visit(n + 1, 0);
  queue<int> q;
  q.push(v);
  visit[v] = 1;
  while (!q.empty())
  {
    int c = q.front();
    q.pop();
    for (auto nxt : adj[c])
    {
      int nv = nxt.first;
      int nk = nxt.second;
      if (visit[nv] || nk < k) continue;
      visit[nv] = 1;
      q.push(nv);
    }
  }
  return accumulate(visit.begin(), visit.end(), - 1);
}

int solve()
{
  for (auto i : query)
  {
    int k = i.first;
    int v = i.second;
    int ret = bfs(k, v);
    cout << ret << '\n';
  }

  return 0;
}

int main() {
    fastio;    
    input();
    solve();      
    return 0;
}
