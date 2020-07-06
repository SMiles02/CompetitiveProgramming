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
int isDivisible(std::vector<int> b, int a, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (b[i] % a != 0)
    {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, z, k;
  cin>>n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin>>z;
    v.push_back(z);
  }
  k = v[0];
  for (int j = 1; j < n; j++)
  {
    if (v[j] < k)
    {
      k = v[j];
    }  
  }  
  if (isDivisible(v, k, n))
  {
    cout<<k;
  }
  else
  {
    cout<<-1;
  }
  return 0;
}