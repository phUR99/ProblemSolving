#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
int dp[100005];
int d, p;
vector<pair<int, int>> arr;
void input()
{
  cin >> d >> p;
  arr.resize(p);
  for (auto &i : arr)
  {
    cin >> i.first >> i.second;
  }
}

int solve()
{
  dp[0] = INF;
  for (auto i : arr)
  {
    int l = i.first;
    int c = i.second;
    for (int j = d; j >= l; j--)
    {
      dp[j] = max(dp[j], min(dp[j - l], c));
    }
  }
  cout << dp[d];
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
