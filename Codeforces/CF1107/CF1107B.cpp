#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n, a, b;
  cin>>n;
  for (int i = 0; i < n; i++)
  {
  	cin>>a>>b;
  	cout<<9*(a-1)+b<<"\n";
  }
  return 0;
}