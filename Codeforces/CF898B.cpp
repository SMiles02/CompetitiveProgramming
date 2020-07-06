#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,a,b;
	cin>>n;
	cin>>a;
	cin>>b;
	for (int i=0;i<=n/a;++i)
	{
		if ((n-i*a)%b==0)
		{
			if (n-a*i<0)
			{
				cout<<"NO";
				return 0;
			}
			else
			{
				cout<<"YES\n";
				cout<<i<<" "<<(n-i*a)/b;
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}