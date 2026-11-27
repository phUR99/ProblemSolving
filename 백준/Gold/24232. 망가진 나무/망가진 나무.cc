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
int cnt[100005];
int ans[100005];
void dfs1(int cur, int par)
{
  for (auto p : adj[cur])
  {
    int dir = p[1];
    int nxt = p[0];
    if (nxt == par)
      continue;
    cnt[1] += dir;
    dfs1(nxt, cur);
  }
}

void dfs2(int cur, int sum)
{
  cnt[cur] = sum;
  for (auto p : adj[cur])
  {
    int dir = p[1];
    int nxt = p[0];
    if(cnt[nxt] != -1)
      continue;
    dfs2(nxt, sum + (dir ? -1 : 1));
  }
}


void dfs3(int cur, int par)
{
  for (auto p : adj[cur])
  {
    int dir = p[1];
    int nxt = p[0];
    int idx = p[2];
    if(nxt == par)
      continue;
    if(dir == 0)
      ans[idx] = 1;
    dfs3(nxt, cur);
  }
}

void input()
{
  cin >> n;
  adj.resize(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back({b, 1, i});
    adj[b].push_back({a, 0, i});
  }
  memset(cnt, -1, sizeof(cnt));
  cnt[1] = 0;
}

int solve()
{
  dfs1(1, -1);
  dfs2(1, cnt[1]);
  int M = -INF;
  int idx = -1;
  for (int i = 1; i <= n; i++)
  {      
      if(cnt[i] > M)
      {        
        M = cnt[i];
        idx = i;
      }
  }
  dfs3(idx, -1);
  for (int i = 0; i < n - 1; i++)
  {
    cout << ans[i];
  }

  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
