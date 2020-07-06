#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x1,y1,x2,y2;
  cin>>x1>>y1;
  cin>>x2>>y2;
  cout<<max(abs(x2-x1),abs(y2-y1));
  return 0;
}