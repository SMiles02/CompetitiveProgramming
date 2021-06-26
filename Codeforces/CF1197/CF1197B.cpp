#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,j,before,after;
  cin>>n;
  int a[n];
  for (int i=0;i<n;++i)
  {
  	cin>>a[i];
  	if (a[i]==n)
  	{
  		j=i;
  	}
  }
  bool done = true;
  before=max(0,j-1);
  after=min(j+1,n-1);
  for (int i=n-1;i>0;--i)
  {
  	//cout<<"Looking for disc "<<i;
  	if (a[before]==i)
  	{
  		//cout<<", found at position "<<before<<"\n";
  		before=max(0,before-1);
  	}
  	else if (a[after]==i)
  	{
  		//cout<<", found at position "<<after<<"\n";
  		after=min(n-1,after+1);
  	}
  	else
  	{
  		done=false;
  		break;
  	}
  }
  if (done)
  {
  	cout<<"YES";
  }
  else
  {
  	cout<<"NO";
  }
  return 0;
}