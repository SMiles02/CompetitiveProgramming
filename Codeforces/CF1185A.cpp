#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort(v.begin(), v.end());
  cout<<max(0,d-v[1]+v[0])+max(0,d-v[2]+v[1]);
  return 0;
}