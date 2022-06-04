#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,m,j,ans;
  cin>>n;
  int a[n];
  for (int i=0;i<n;++i)
  {
  	cin>>a[i];
  }
  cin>>m;
  int b[m];
  for (int i=0;i<m;++i)
  {
  	cin>>b[i];
  }
  /**cout<<"a: ";
  for (int i=0;i<n;++i)
  {
  	cout<<a[i]<<" ";
  }
  cout<<"\n";
  cout<<"b: ";
  for (int i=0;i<m;++i)
  {
  	cout<<b[i]<<" ";
  }**/
  j=0;
  ans=0;
  sort(a,a+n); 
  sort(b,b+m);
  /**cout<<"\na: ";
  for (int i=0;i<n;++i)
  {
  	cout<<a[i]<<" ";
  }
  cout<<"\n";
  cout<<"b: ";
  for (int i=0;i<m;++i)
  {
  	cout<<b[i]<<" ";
  }
  cout<<"\n";**/
  for (int i=0;i<n;++i)
  {
  	for (j=j;j<m;++j)
  	{
  		//cout<<"j: "<<j<<"\n";
  		if (abs(a[i]-b[j])<=1)
  		{
  			//cout<<i<<" "<<j<<"\n";
  			//cout<<"Actual values: "<<a[i]<<" "<<b[j]<<"\n";
  			++ans;
  			++j;
  			break;
  		}
  		else if (a[i]<b[j])
  		{
  			break;
  		}
  	}
  }
  cout<<ans;
  return 0;
}