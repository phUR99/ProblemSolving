#include <bits/stdc++.h>
using namespace std;

void input();
int solve();

typedef long long ll;
typedef pair<int, int> pii;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
int dp[20][1 << 10][2];
int num[20];
ll n, k, l;
void input()
{
  memset(dp, -1, sizeof(dp));
  cin >> n >> k;
  string str = to_string(n);
  l = str.size();
  for (int i = 0; i < l; i++)
  {
    num[i] = str[i] - '0';
  }
}

int func(int idx, int state, int big, string tmp)
{
  int cnt = 0;
  for (int i = 0; i < 10; i++)
  {
    if (state & (1 << i))
      cnt++;
  }

  if(idx == l)
  {
    if(cnt != k)
      return 0;
    cout << tmp;
    exit(0);
  }
  int &ret = dp[idx][state][big];
  if(ret != -1)
    return ret;
  ret = 0;
  for (int i = 0; i < 10; i++)
  {
    if(!big && num[idx] > i) continue;
    if(num[idx] < i)
    {
      ret |= func(idx + 1, state | (1 << i), 1, tmp + to_string(i));      
    }
    else
    {
      ret |= func(idx + 1, state | (1 << i), big, tmp + to_string(i));      
    }  
  }
  return ret;
}

int solve()
{
  if(l < k)
  {
    string ans = "1023456789";
    cout << ans.substr(0, k);
  }
  else
  {
    func(0, 0, 0, "");
    l++;
    for (int i = 0; i < l; i++)
    {
      num[i] = 0;
    }
    num[0] = 1;
    memset(dp, -1, sizeof(dp));
    func(0, 0, 0, "");
  }
  return 0;
}

int main() {
    fastio;    
    input();
    solve();
    
    
    return 0;
}
