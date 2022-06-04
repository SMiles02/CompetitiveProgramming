#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n,m,a,b;
  cin>>n>>m>>a>>b;
  if (n%m==0)
  {
  	cout<<0;
  }
  else
  {

  	cout<<min((m-(n%m))*a, b*(n%m));
  }
  return 0;
}