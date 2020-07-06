#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,i,maxFirm,q,l,r,d,b,c;
  cin>>n;
  int a[n];
  for (i=0;i<n;i++)
  {
  	cin>>a[i];
  }
  cin>>q;
  for (i=0;i<q;i++)
  {
  	maxFirm = 0;
  	cin>>l>>r;
  	for (d=l-1;d<r;d++)
  	{
  		for (b=d+1;b<r;b++)
  		{
  			for (c=b+(b-d);c<r;c++)
  			{
  				maxFirm = max(maxFirm,a[d]+a[b]+a[c]);
  			}
  		}
  	}
  	cout<<maxFirm<<"\n";
  }
  return 0;
}