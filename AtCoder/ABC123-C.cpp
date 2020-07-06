#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int l,r,k,z,ans,current,i,j;
  cin>>l>>r;
  vector<int> v;
  k = std::min(r,l+2018);
  for (z=l;z<=k;z++)
  {
  	v.push_back(z%2019);
  }
  k=v.size();
  ans=2019;
  for (i=0;i<k;i++)
  {
  	for (j=i+1;j<k;j++)
  	{
  		current=(v[i]*v[j])%2019;
  		if (current < ans)
  		{
  			ans=current;
  		}
  	}
  }
  cout<<ans;
  return 0;
}