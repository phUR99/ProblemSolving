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
int a[100005];
vector<vector<int>> adj;
int cnt1[100005], cnt2[100005];
ll sum[100005];

void dfs(int cur, int par)
{
  if(a[cur])
    cnt1[cur]++;
  else
    cnt2[cur]++;
  for (int nxt: adj[cur])
  {
      if(nxt == par) continue;
      dfs(nxt, cur);
      cnt1[cur] += cnt1[nxt];
      cnt2[cur] += cnt2[nxt];
  }  
  int b = cnt2[cur] - (a[cur] ? 0 : 1);

  for (int nxt : adj[cur])
  {
      if(nxt == par) continue;
      sum[cur] += 1LL * cnt1[nxt] * (b - cnt2[nxt]);      
  }
}


void input()
{
  cin >> n;
  adj.resize(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

int solve()
{
  dfs(1, -1);
  ll R = cnt1[1];
  ll B = cnt2[1];
  for (int i = 2; i <= n; i++)
  {
    ll r = cnt1[i] - (a[i] ? 1 : 0);
    ll b = cnt2[i] - (a[i] ? 0 : 1);
    sum[i] = sum[i] + 1LL * (R - cnt1[i]) * b + 1LL * (B - cnt2[i]) * r;    
  }
  int q;
  cin >> q;
  while (q--)
  {
    int t;
    cin >> t;
    cout << sum[t] << '\n';
  }

  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
