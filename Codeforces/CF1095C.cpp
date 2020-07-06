#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k,i,power,j;
  power=536870912;
  cin>>n>>k;
  int a[k];
  i=0;
  if (k>n)
  {
  	cout<<"NO";
  	return 0;
  }
  if (n==2*536870912)
  {
  	a[0]=2*536870912;
  	++i;
  	n=0;
  }
  while (n>0 && i<k)
  {
  	if (n>=power)
  	{
  	  n-=power;
   	  a[i]=power;
  	  ++i;
  	}
  	power/=2;
  }
  //cout<<"i: "<<i<<"\n";
  //cout<<"n: "<<n<<"\n";
  //cout<<"k: "<<k<<"\n";
  if (i <= k && n == 0)
  {
	j=0;
	while (i < k)
	{
	  while (i < k && a[j] > 1)
	  {
	  	a[i]=a[j]/2;
	  	a[j]/=2;
	  	++i;
	  }
	  ++j;
	}
	cout<<"YES\n";
	for (int m=0;m<k;m++)
	{
		cout<<a[m]<<" ";
	}
  }
  else
  {
  	cout<<"NO";
  }
  return 0;
}