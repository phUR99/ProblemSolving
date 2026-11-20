#include <bits/stdc++.h>
using namespace std;
int n, m, l;
void input();
int solve();
bool out(int nx, int ny) { return nx < 0 || nx >= n || ny < 0 || ny >= n; }
int bfs();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define H 1
#define C 2

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
int ans = INF;

vector<vector<int>> mp;
vector<pii> c_list;
vector<int> visited;

void input()
{
  cin >> n >> m;
  mp.resize(n, vector<int>(n));
  for (auto &i : mp) for (auto &j : i)
      cin >> j;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(mp[i][j] == C)
        c_list.push_back({i, j});
    }
  }
  l = c_list.size();
  visited.resize(l);
}

void dfs (int idx, int cnt)
{
  if(cnt == m)
  {
    ans = min(bfs(), ans);
    return;
  }
  for (int i = idx; i < l; i++)
  {
    visited[i] = 1;
    dfs(i + 1, cnt + 1);
    visited[i] = 0;
  }
}

int bfs()
{
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  queue<pii> q;
  vector<vector<int>> t_mp, dist;
  t_mp = mp;
  dist.resize(n, vector<int>(n, -1));
  for (int i = 0; i < l; i++)
  {
    int x = c_list[i].first;
    int y = c_list[i].second;
    if(visited[i])
    {
      q.push(make_pair(x, y));
      dist[x][y] = 0;
    }
  }
  while (!q.empty())
  {
    auto p_cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; dir++)
    {
      int nx = p_cur.first + dx[dir];
      int ny = p_cur.second + dy[dir];
      
      if (out(nx, ny)) continue;
      if(dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[p_cur.first][p_cur.second] + 1;
      q.push(make_pair(nx, ny));
    }
  }
  int ret = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(t_mp[i][j] == H)
        ret += dist[i][j];
    }
  }
  return ret;
}

int solve()
{
  dfs(0, 0);
  cout << ans;
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
