#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,i,j,a,b,ans;
  ans=0;
  cin>>n>>m;
  for (i=0;i<n;i++)
  {
  	for (j=0;j<m;j++)
  	{
  		cin>>a>>b;
  		if (a==1||b==1)
  		{
  			ans++;
  		}
      //cout<<ans<<"\n";
      //cout<<a<<" "<<b<<"\n";
  	}
  }
  cout<<ans;
  return 0;
}