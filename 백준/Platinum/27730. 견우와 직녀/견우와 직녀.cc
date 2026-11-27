#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
int n, m;
vector<vector<pair<int, int>>> adj1, adj2;

ll sum1[100005], sum2[100005];
int cnt1[100005], cnt2[100005];

void dfs(int cur, int par, ll sum[], vector<vector<pair<int, int>>> &adj, ll s, int cnt[], int idx)
{
  sum[idx] += s;
  cnt[cur] = 1;
  for (auto p : adj[cur])
  {
    int nxt = p.first;
    int cost = p.second;
    if(nxt == par) continue;    
    dfs(nxt, cur, sum, adj, s + cost, cnt, idx);
    cnt[cur] += cnt[nxt];
  }
}
void dfs2(int cur, int par, ll sum[], vector<vector<pair<int, int>>>& adj, ll s, int cnt[])
{
  sum[cur] = s;
  for (auto p : adj[cur])
  {
    int nxt = p.first;
    int cost = p.second;
    if(nxt == par) continue;
    ll ns = sum[cur] + 1LL * (adj.size() - 1 - 2 * cnt[nxt]) * cost;
    dfs2(nxt, cur, sum, adj, ns, cnt);
  }  
}

void input()
{
  cin >> n;
  adj1.resize(n + 1);
  for (int i = 0; i < n - 1; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adj1[a].push_back({b, c});
    adj1[b].push_back({a, c});
  }
  cin >> m;
  adj2.resize(m + 1);
  for (int i = 0; i < m - 1; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adj2[a].push_back({b, c});
    adj2[b].push_back({a, c});
  }
}

int solve()
{
  dfs(1, -1, sum1, adj1, 0, cnt1, 1);
  dfs(1, -1, sum2, adj2, 0, cnt2, 1);
  dfs2(1, -1, sum1, adj1, sum1[1], cnt1);
  dfs2(1, -1, sum2, adj2, sum2[1], cnt2);

  int idx1 = 1, idx2 = 1;
  ll m1 = LINF, m2 = LINF;  
  for (int i = 1; i <= n; i++)
  {   
    if (m1 > sum1[i])
    {
      idx1 = i;
      m1 = sum1[i];
    }    
  }
  for (int i = 1; i <= m; i++)
  {    
    if (m2 > sum2[i])
    {
      idx2 = i;
      m2 = sum2[i];
    }
  }
  cout << idx1 << ' ' << idx2 << '\n';  
  cout << 1LL * m * m1 + 1LL * n * m2 + 1LL * n * m;
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
