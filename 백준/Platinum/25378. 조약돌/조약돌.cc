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
vector<int> arr;
int dp[2505];
void input()
{
  cin >> n;
  arr.resize(n);
  for (auto &i : arr)
  {
    cin >> i;
  }

  memset(dp, -1, sizeof(dp));
}

int func(int idx)
{
  if(idx == n)
    return 0;
  int &ret = dp[idx];
  if(ret != -1)
    return ret;
  ret = func(idx + 1);
  int sum = arr[idx];
  for (int i = idx + 1; i < n; i++)
  {
    sum = arr[i] - sum;
    if(sum < 0) break;
    if(sum == 0)
      ret = max(ret, 1 + func(i + 1));
  }
  return ret;
}

int solve()
{
  int ans = n - func(0);  
  cout << ans;
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
