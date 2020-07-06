#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t,n,big,big2,a,b;
  cin>>t;
  for (int i=0;i<t;++i)
  {
	cin>>n;
	cin>>a;
	cin>>b;
	big=max(a,b);
	big2=min(a,b);
	for (int j=2;j<n;++j)
	{
		cin>>a;
		if (a>=big)
		{
			big2=big;
			big=a;
		}
		else if (a>big2)
		{
			big2=a;
		}
	}
	cout<<min(big2-1,n-2)<<"\n";
  }
  return 0;
}