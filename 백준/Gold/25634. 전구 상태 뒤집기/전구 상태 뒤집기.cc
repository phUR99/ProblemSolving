#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

int arr[200005];
int state[200005];
int n;

void input()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> state[i];
  }  
}

int solve()
{  
  int base = 0;
  int best = -INF;
  int cur = 0;
  for (int i = 0; i < n; i++)
  {
    if(state[i])
      base += arr[i];
    int p = (state[i] ? -arr[i] : arr[i]);
    cur = max(p, cur + p);
    best = max(best, cur);
  }
  cout << base + best;

  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
