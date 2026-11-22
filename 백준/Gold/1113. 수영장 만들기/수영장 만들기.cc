#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
vector<vector<int>> mp;
vector<vector<int>> visited;
int n, m;

void input()
{
  cin >> n >> m;
  mp.resize(n);
  visited.resize(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++)
  {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; j++)
    {
      mp[i].push_back(tmp[j] - '0');
    }
  }
}

bool out(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }
void bfs(int x, int y, int p)
{
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  vector<vector<int>> t_visited(n, vector<int>(m, -1));
  t_visited[x][y] = p;
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  while (!q.empty())
  {
    auto qc = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nx = qc.first + dx[i];
      int ny = qc.second + dy[i];
      if(out(nx, ny))
        return;
      if(t_visited[nx][ny] != -1 || mp[nx][ny] >= p) continue;
      q.push(make_pair(nx, ny));
      t_visited[nx][ny] = p;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(t_visited[i][j] != -1)
        visited[i][j] = t_visited[i][j];
    }
  }
  return;
}
void print()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << visited[i][j];
    }
    cout << '\n';
  }
  cout << '\n';
  cout << "----------------------------------------";
  cout << '\n';
}


int solve()
{
  int ret = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      for (int k = 9; k >= 1; k--)
      { 
        if(visited[i][j] == -1 && mp[i][j] <= k)
        {
          bfs(i, j, k);
          // cout << i << ' ' << j << ' ' << k << '\n';
          // print();
        }
      }    
    }    
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {      
      if (visited[i][j] != -1)
        ret += max(0, visited[i][j] - mp[i][j]);
    }    
  }
  cout << ret;

  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
