#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,j;
  cin>>n>>m;
  for (int i = 1; i <= n; i++)
  {
  	if (i % 4 == 1 || i % 4 == 3)
  	{
  		for (j=0;j<m;j++)
  		{
  			cout<<"#";
  		}
  		cout<<"\n";
  	}
  	else if (i % 4 == 2)
  	{
  		for (j=0;j<m-1;j++)
  		{
  			cout<<".";
  		}
  		cout<<"#\n";
  	}
  	else
  	{
  		cout<<"#";
  		for (j=0;j<m-1;j++)
  		{
  			cout<<".";
  		}
  		cout<<"\n";
  	}
  }
  return 0;
}