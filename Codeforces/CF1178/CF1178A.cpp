#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,with,against,k;
  cin>>n;
  int a[n];
  cin>>a[0];
  vector<int> v;
  v.push_back(1);
  with=a[0];
  against=0;
  for (int i=1;i<n;i++)
  {
  	cin>>a[i];
  	if (a[i]*2<=a[0])
  	{
  		v.push_back(i+1);
  		with+=a[i];
  	}
  	else
  	{
  		against+=a[i];
  	}
  }
  k = v.size();
  if (against>=with)
  {
  	cout<<0;
  	return 0;
  }
  cout<<k<<"\n";
  for (int i=0;i<k;++i)
  {
  	cout<<v[i]<<" ";
  }
  return 0;
}