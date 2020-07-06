#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int k2,k3,k5,k6,m,ans;
  cin>>k2>>k3>>k5>>k6;
  m = min({k2,k5,k6});
  ans=m*256;
  k2-=m;
  k5-=m;
  k6-=m;
  m=min({k3,k2});
  ans+=m*32;
  cout<<ans;
  return 0;
}