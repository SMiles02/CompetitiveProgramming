#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k,a,b,i,c,d;
  string s;
  cin>>n>>k;
  cin>>s;
  for (i=0;i<n;i++)
  {
  	//cout<<"I: "<<i<<" "<<s[i]<<"\n";
  	if (s[i] == 'G')
  	{
  		a=i;
  		//cout<<"A: "<<a<<"\n";
  	}
  	else if (s[i] == 'T')
  	{
  		b=i;
  		//cout<<"B: "<<b<<"\n";
  	}
  }
  c=min(a,b);
  d=max(a,b);
  if ((d-c)%k==0)
  {
  	for (i=c+k;i<d;i+=k)
  	{
  		if (s[i] != '.')
  		{
  			cout<<"NO";
  			return 0;
  		}
  	}
  	cout<<"YES";
  }
  else
  {
  	//cout<<c<<" "<<d<<"\n";
  	cout<<"NO";
  }
  return 0;
}