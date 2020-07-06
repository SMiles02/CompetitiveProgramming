#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a,b,i,n;
  a=0;
  b=0;
  string s;
  cin>>n;
  cin>>s;
  for (i=0;i<n;++i)
  {
  	if (s[i]=='0')
  	{
  		++a;
  	}
  	else
  	{
  		++b;
  	}
  }
  if (a==b)
  {
  	cout<<"2\n";
  	cout<<s[0]<<" ";
  	for (i=1;i<n;i++)
  	{
  		cout<<s[i];
  	}
  }
  else
  {
  	cout<<1<<"\n";
  	cout<<s;
  }
  return 0;
}