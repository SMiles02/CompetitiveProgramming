#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a,b,c,d,e;
  string s;
  cin>>s;
  int n = s.length();
  for (a = 0; a < n; ++a)
  {
  	if (s[a] == 'h')
  	{
  		break;
  	}
  }
  for (b = a+1; b < n; ++b)
  {
  	if (s[b] == 'e')
  	{
  		break;
  	}
  }
  for (c = b+1; c < n; ++c)
  {
  	if (s[c] == 'l')
  	{
  		break;
  	}
  }
  for (d = c+1; d < n; ++d)
  {
  	if (s[d] == 'l')
  	{
  		break;
  	}
  }
  for (e = d; e < n; ++e)
  {
  	if (s[e] == 'o')
  	{
  		cout<<"YES";
  		return 0;
  	}
  }
  cout<<"NO";
  return 0;
}