#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,i,j,k,l,hL,vL;
  int a[4];
  ll ans;
  cin>>n;
  vector<int[4]> h;
  vector<int[4]> v;
  for (i = 0; i < n; i++)
  {
  	for (j=0;j<4;j++)
  	{
  		cin<<a[j];
  	}
  	if (x1==x2)
  	{
  		v.push_back(a);
  	}
  	else
  	{
  		h.push_back(a);
  	}
  }
  hL = h.size();
  vL = v.size();
  for (i=0;i<hL-1;i++)
  {
  	for (j=i+1;j<hL;j++)
  	{
  		for (k=0;k<vL-1;k++)
  		{
  			if (min(h[i][0],h[i][2]) <= v[k][0])
  			{
  				if (max(h[i][0],h[i][2]) >= v[k][0])
  				{
  					if (min(h[j][0],h[j][2]) <= v[k][0])
  					{
  						if (max(h[j][0],h[j][2]) >= v[k][0])
  						{
  							for (l=k+1;l<vL;l++)
  							{
  								if (min(h[i][0],h[i][2]) <= v[l][0])
					  			{
					  				if (max(h[i][0],h[i][2]) >= v[l][0])
					  				{
					  					if (min(h[j][0],h[j][2]) <= v[l][0])
					  					{
					  						if (max(h[j][0],h[j][2]) >= v[l][0])
					  						{
					  							ans++;
					  						}
					  					}
					  				}
					  			}
  							}
  						}
  					}
  				}
  			}
  		}
  	}
  }
  cout<<ans;
  return 0;
}