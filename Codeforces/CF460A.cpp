#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,i;
  cin>>n>>m;
  i=0;
  while (n>0)
  {
  	++i;
  	--n;
  	if (i%m==0 && i!=1)
  	{
  		++n;
  	}
  }
  cout<<i;
  return 0;
}