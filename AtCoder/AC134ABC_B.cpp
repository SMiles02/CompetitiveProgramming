#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,d,ans;
  cin>>n>>d;
  d=(2*d)+1;
  if (n<=d)
  {
  	ans=1;
  }
  else if (n%d==0)
  {
  	ans=n/d;
  }
  else
  {
  	ans=n/d;
  	++ans;
  }
  cout<<ans;
  return 0;
}