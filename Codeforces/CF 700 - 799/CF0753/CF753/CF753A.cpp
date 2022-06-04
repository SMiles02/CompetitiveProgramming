#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin>>n;
  for (int i=1;i<47;++i)
  {
  	if (i*(i+1)>2*n)
  	{
  		cout<<i-1<<"\n";
  		for (int j=1;j<i-1;++j)
  		{
  			cout<<j<<" ";
  			n-=j;
  		}
  		cout<<n;
  		return 0;
  	}
  }
  return 0;
}