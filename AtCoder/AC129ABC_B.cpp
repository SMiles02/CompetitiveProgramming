#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,s1,s2,k,mini;
  cin>>n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
  	cin>>a[i];
  }
  mini=1000000;
  for (int t = 1; t < n; t++)
  {
  	s1=0;
  	s2=0;
  	for (int i=0;i<n;i++)
  	{
  		k=a[i];
  		if (i>t)
  		{
  			s2+=k;
  		}
  		else
  		{
  			s1+=k;
  		}
  	}
  	mini=std::min(mini,abs(s1-s2));
  }
  cout<<mini;
  return 0;
}