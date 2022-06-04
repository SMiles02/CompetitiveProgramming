#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,i,j,ans;
  cin>>n;
  int a[n+2];
  a[0]=0;
  a[n+1]=1001;
  for (i=1;i<=n;i++)
  {
  	cin>>a[i];
  }
  ans=0;
  for (i=0;i<=n+1;i++)
  {
  	for (j=i+2;j<=n+1;j++)
  	{
  		if (a[i] - i == a[j] - j)
  		{
  			ans = std::max(ans, j-i-1);
  		}
  		else
  		{
  			break;
  		}
  	}
  }
  cout<<ans;
  return 0;
}