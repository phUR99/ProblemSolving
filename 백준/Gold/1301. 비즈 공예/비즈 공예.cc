#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define N 5
#define M 10 + 1
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
int n;
vector<int> arr(N + 2);
ll dp[M][M][M][M][M][N+1][N+1];
void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  arr[N] = N;
  arr[N + 1] = N;
  memset(dp, -1, sizeof(dp));
}

ll func(vector<int> a)
{
  if(accumulate(a.begin(), a.end(), -a[5]-a[6]) == 0)
    return 1;
  ll &ret = dp[a[0]][a[1]][a[2]][a[3]][a[4]][a[5]][a[6]];
  if(ret != -1)
    return ret;
  ret = 0;
  for (int i = 0; i < n; i++)
  {
    if(a[5] == i || a[i] == 0 || a[6] == i) continue;
    vector<int> tmp;
    tmp = a;
    tmp[i]--;
    tmp[6] = tmp[5];
    tmp[5] = i;
    ret += func(tmp);
  }
  return ret;
}

int solve()
{
  ll ans = func(arr);
  cout << ans;
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
