#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin>>s;
  n=s.length();
  bool done = false;
  for (int i=0;i<n-1;++i)
  {
  	if (s[i]=='A'&&s[i+1]=='B')
  	{
  		for (int j=i+2;j<n-1;++j)
  		{
  			if (s[j]=='B'&&s[j+1]=='A')
  			{
  				done=true;
  				break;
  			}
  		}
  		break;
  	}
  }
  for (int i=0;i<n-1;++i)
  {
  	if (s[i]=='B'&&s[i+1]=='A')
  	{
  		for (int j=i+2;j<n-1;++j)
  		{
  			if (s[j]=='A'&&s[j+1]=='B')
  			{
  				done=true;
  				break;
  			}
  		}
  		break;
  	}
  }
  if (done)
  {
  	cout<<"YES";
  }
  else
  {
  	cout<<"NO";
  }
  return 0;
}