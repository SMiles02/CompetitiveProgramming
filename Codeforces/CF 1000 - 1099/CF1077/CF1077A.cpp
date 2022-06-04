#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll t, a, b, k;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
  	cin >> a >> b >> k;
  	if (k % 2 == 0)
  	{
  		cout << (a - b) * (k / 2) << "\n";
  	}
  	else
  	{
  		cout << (a - b) * ((k - 1) / 2) + a << "\n";
  	}
  }
  return 0;
}