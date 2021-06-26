#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int w,h;
  ll ans;
  cin>>w>>h;
  ans=2;
  --w;
  while (w+h>0)
  {
  	--w;
  	ans*=2;
  	ans%=998244353;
  }
  cout<<ans;
  return 0;
}