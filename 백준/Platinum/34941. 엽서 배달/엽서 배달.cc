#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
int n;
vector<vector<array<int, 3>>> adj;
int cnt[300005];
ll sum[300005];

void input()
{
  cin >> n;
  adj.reserve(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    adj[a].push_back({b, c, d});
    adj[b].push_back({a, d, c});
  }  
}

void dfs(int cur, int par, ll s)
{
  sum[1] += s;
  cnt[cur] = 1;
  for (auto p : adj[cur])
  {
    int nxt = p[0];
    int cost = p[1];
    if(nxt == par) continue;
    dfs(nxt, cur, s + cost);
    cnt[cur] += cnt[nxt];
  }
}

void dfs2(int cur, int par, ll s)
{
  sum[cur] = s;
  for (auto p : adj[cur])
  {
    int nxt = p[0];
    int pos = p[1];
    int neg = p[2];
    if (nxt == par)
      continue;
    ll ns = s - 1LL * cnt[nxt] * p[1] + 1LL * (n - cnt[nxt]) * p[2];
    dfs2(nxt, cur, ns);
  }
}

int solve()
{
  dfs(1, -1, 0);
  dfs2(1, -1, sum[1]);
  ll ans = *min_element(sum + 1, sum + n + 1);
  cout << ans;
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
