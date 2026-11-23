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
vector<array<int, 3>> arr;
int dp[1005][1005];

void input()
{
  cin >> n;
  arr.resize(n);
  for (auto &i : arr)
  {
    cin >> i[0] >> i[1] >> i[2];
  }
  memset(dp, -1, sizeof(dp));
}

int func(int s, int t)
{

  int &ret = dp[s][t];
  if(ret != -1)
    return ret;
  ret = 0;
  int cnt = 0;
  for (auto i : arr)
  {
    if(i[0] <= s || i[1] <= t)
    {
      cnt += i[2];
      ret++;
    }
  }
  cnt -= s + t - 2;
  for (int i = 0; i <= cnt; i++)
  {
    ret = max(ret, func(min(1000, s + i), min(1000, t + cnt - i)));
  }

  return ret;
}

int solve()
{
  int ans = func(1, 1);
  cout << ans;
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
