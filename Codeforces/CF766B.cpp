#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int a, std::vector<int> b) {
	int len = b.size();
  	for (int i = 0; i < len; i++)
  	{
  		if (b[i] == a)
  		{
  			return i;
  		}
  	}
  	return -1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, i;
  cin>>n;
  int a[n];
  for (i = 0; i < n; i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  for (i = 1; i < n-1; i++)
  {
    if (a[i-1] + a[i] > a[i+1])
    {
      cout<<"YES";
      return 0;
    }
  }
  cout<<"NO";
  return 0;
}