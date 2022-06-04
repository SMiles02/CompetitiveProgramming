#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k,ans;
  cin>>n>>k;
  int a[n];
  for (int i=0;i<n;++i)
  {
  	cin>>a[i];
  }
  ans=0;
  for (int i=0;i<n-1;++i)
  {
  	if (a[i]+a[i+1]<k)
  	{
  		ans+=k-a[i]-a[i+1];
  		a[i+1]=k-a[i];
  	}
  }
  cout<<ans<<"\n";
  for (int i=0;i<n;++i)
  {
  	cout<<a[i]<<" ";
  }
  return 0;
}