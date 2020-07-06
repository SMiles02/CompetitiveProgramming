#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,cur,cnt;
  cin>>n;
  int a[n+1];
  int ans[n+1];
  cnt=0;
  for (int i=1;i<=n;++i)
  {
  	cin>>a[i];
  }
  for (int i=n;i>0;--i)
  {
  	cur=0;
  	for (int j=2;j*i<=n;++j)
  	{
  		cur+=ans[i*j];
  	}
  	if (cur%2==a[i]%2)
  	{
  		ans[i]=0;
  	}
  	else
  	{
  		ans[i]=1;
  		++cnt;
  	}
  }
  cout<<cnt<<"\n";
  for (int i=1;i<=n;++i)
  {
  	if (ans[i]==1)
  	{
  		cout<<i<<" ";
  	}
  }
  return 0;
}