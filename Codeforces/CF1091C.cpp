#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n;
  std::vector<ll> ans;
  cin>>n;
  ans.push_back(1);
  ans.push_back((n*(n+1))/2);
  for (ll i = 2; i*i <= n; i++)
  {
    if (n % i == 0)
    {
      if (i * i == n)
      {
        ans.push_back(n*(i-1)/2 + i);
      }
      else
      {
        ans.push_back(n*(i-1)/2 + i);
        ans.push_back(n*(n/i-1)/2 + n/i);
      }
    }
  }
  sort(ans.begin(),ans.end());
  for (int i = 0; i < ans.size(); ++i)
  {
    cout << ans[i] << " \n"[i==ans.size()-1];
  }
  return 0;
}