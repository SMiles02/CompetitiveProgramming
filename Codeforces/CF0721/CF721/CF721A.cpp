#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k, i, j;
  string s;
  vector<int> v;
  cin >> n;
  cin >> s;
  for (i = 0; i < n; ++i)
  {
  	if (s[i] == 'B')
  	{
  		k = 0;
	  	for (j = i; j < n; ++j)
	  	{
	  		if (s[j] == 'B')
	  		{
	  			++k;
	  		}
	  		else
	  		{
	  			break;
	  		}
	  	}
	  	i = j;
	  	v.push_back(k);
	}
  }
  cout << v.size() << "\n";
  for(auto&& x: v)
  {
  	cout << x << '\n';
  }
  return 0;
}