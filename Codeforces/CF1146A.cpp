#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  int n, a;
  cin >> s;
  n = s.size();
  a = std::count(s.begin(), s.end(), 'a');
  //cout << n << " " << a << "\n";
  cout << std::min(2 * a - 1, n);
  return 0;
}