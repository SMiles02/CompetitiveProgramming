#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll n,k,i,x;
  cin>>n>>k;
  x=10000000000000000;
  for (i=1;i<k;i++)
  {
  	if (n%i==0)
  	{
  		x=std::min(x,(n/i)*k+i);
  	}
  }
  cout<<x;
  return 0;
}