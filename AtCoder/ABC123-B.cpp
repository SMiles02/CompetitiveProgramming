#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,d,i,j,k,ans;
  float dist,thisDist;
  cin>>n>>d;
  int x[n][d];
  for (i=0;i<n;i++)
  {
  	for (j=0;j<d;j++)
  	{
  		cin>>x[i][j];
  	}
  }
  ans=0;
  for (i=0;i<n;i++)
  {
  	for (j=i+1;j<n;j++)
  	{
  		//cout<<i<<" "<<j<<"\n";
  		dist=0;
  		for (k=0;k<d;k++)
  		{
  			thisDist = x[i][k] - x[j][k];
  			thisDist*=thisDist;
  			dist+=thisDist;
  		}
  		dist = sqrt(dist);
  		if (floor(dist) == dist)
  		{
  			//cout<<"test\n";
  			ans++;
  		}
  	}
  }
  cout<<ans;
  return 0;
}