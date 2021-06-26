#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k,minOdd,i;
  ll s;
  cin>>n;
  s=0;
  minOdd=1000000001;
  for (i=0;i<n;i++)
  {
  	cin>>k;
  	s+=k;
  	if (k%2==1)
  	{
  		minOdd=min(minOdd,k);
  	}
  }
  if (s%2==1)
  {
  	s-=minOdd;
  }
  cout<<s;
  return 0;
}