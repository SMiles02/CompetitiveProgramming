#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,i,last,now;
  cin>>n;
  vector<int> v;
  cin>>last;
  for (i=1;i<n;++i)
  {
  	cin>>now;
  	if (now == 1)
  	{
  		v.push_back(last);
  	}
  	last = now;
  }
  v.push_back(last);
  cout<<v.size()<<"\n";
  for (auto j=v.begin();j!=v.end();++j)
  {
  	cout<<*j<<" ";
  }
  return 0;
}