#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
int n, k;
ll fibo[50];
ll dp[50];

void input()
{
  cin >> n >> k;
  fibo[1] = 1;
  fibo[0] = 1;
  for (int i = 2; i < 50; i++)
  {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
}

int solve()
{  
  int l = k - 1;
  int r = n - k;

  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i < 50; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2] + fibo[i + 2] - 2;
  }
  cout << fibo[l] * fibo[r] + dp[l] * fibo[r] + fibo[l] * dp[r];
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
