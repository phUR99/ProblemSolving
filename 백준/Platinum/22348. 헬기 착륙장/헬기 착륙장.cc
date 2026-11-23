#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int MOD = 1e9 + 7;
const int H = 500;
const int B = 50050;

int pre[H + 1][B + 1];
int a, b;

void precompute()
{
  vector<int> cnt(B + 1, 0);  
  cnt[0] = 1;                 

  for (int h = 1; h <= H; h++)
  {
    
    for (int p = B; p >= h; p--)
      cnt[p] = (cnt[p] + cnt[p - h]) % MOD;

    pre[h][0] = cnt[0];
    for (int p = 1; p <= B; p++)
      pre[h][p] = (pre[h][p - 1] + cnt[p]) % MOD;
  }
}


ll rangeSum(int h, int lo, int hi)
{
  ll r = pre[h][hi] - (lo > 0 ? pre[h][lo - 1] : 0);
  return (r % MOD + MOD) % MOD;  
}

void solve()
{
  ll ans = 0;
  for (int h = 1; h <= H; h++)
  {
    ll S = (ll)h * (h + 1) / 2;  
    if (S > a + b) break;        
    int lo = max(0LL, S - a);  
    ans = (ans + rangeSum(h, lo, b)) % MOD;
  }
  cout << ans << '\n';
}

int main()
{
  fastio;
  precompute();       

  int t;
  cin >> t;
  while (t--)
  {
    cin >> a >> b;
    solve();
  }
  return 0;
}
