#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,current,longest;
  cin>>n;
  int a[n];
  for (int j = 0; j < n; j++)
  {
  	cin>>a[j];
  }
  longest = 1;
  current = 1;
  for (int i = 1; i < n; i++)
  {
  	if (a[i] > a[i-1])
  	{
  		current++;
  	}
  	else
  	{
  		longest = std::max(longest, current);
  		current = 1;
  	}
  }
  longest = std::max(longest, current);
  cout<<longest;
  return 0;
}