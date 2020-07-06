#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a,b,reusable,ans;
  cin>>a>>b;
  ans=0;
  reusable=0;
  while (a>0)
  {
  	ans+=a;
  	reusable+=a;
  	a=0;
  	a+=(reusable-(reusable%b))/b;
  	reusable%=b;
  }
  cout<<ans;
  return 0;
}