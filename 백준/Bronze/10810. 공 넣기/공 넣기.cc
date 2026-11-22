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
vector<array<int, 3>> query;
vector<int> arr;

void input()
{
  cin >> n >> m;
  arr.resize(n + 1);
  query.resize(m);
  for (auto &i : query)
  {
    cin >> i[0] >> i[1] >> i[2];
  }
}

int solve()
{
  for (auto &it : query)
  {
    for (int i = it[0]; i <= it[1]; i++)
    {
      arr[i] = it[2];
    }
      
  }
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << ' ';
  }

  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
