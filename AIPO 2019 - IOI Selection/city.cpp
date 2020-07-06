#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,maxH,k,h,mostEmpty,c;
  ll ans;
  maxH=0;
  cin>>n;
  int a[n][2];
  for (int i=0; i<n; i++)
  {
  	cin>>a[i][0]>>a[i][1];
  	maxH=std::max(maxH,a[i][0]);
  }
  int occupied[maxH];
  set<int> doneFloors;
  for (int i=n-1;i>=0;i--)
  {
  	h = a[i][0];
  	k = a[i][1];
  	doneFloors.clear();
  	while (k>0)
  	{
  		mostEmpty=10001;
  		for (int j = 0; j<h;j++)
  		{
  			if (doneFloors.find(j) == doneFloors.end())
  			{
  				mostEmpty=std::min(mostEmpty,occupied[j]);
  			}
  		}
  		for (int j = h-1; j>=0;j--)
  		{
  			if (occupied[j] == mostEmpty)
  			{
  				if (doneFloors.find(j) == doneFloors.end())
  				{
  					k--;
	  				doneFloors.insert(j);
	  				occupied[j]++;
	  				if (k==0)
	  				{
	  					break;
	  				}
  				}
  			}
  		}
  	}
  }
  for (int i = 0; i < maxH; i++)
  {
  	c = occupied[i];
  	ans+=(c*c-c)/2;
  }
  cout<<ans;
  return 0;
}