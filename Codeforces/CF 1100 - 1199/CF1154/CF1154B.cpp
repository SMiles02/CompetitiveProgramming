#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin>>n;
	vector<int> v;
	while (n--)
	{
		cin>>k;
		if (index(k,v)==-1)
		{
			v.push_back(k);
		}
	}
	k=v.size();
	if (k>3)
	{
		cout<<-1;
		return 0;
	}
	sort(v.begin(),v.end());
	if (k==3)
	{
		if (v[2]-v[1]==v[1]-v[0])
		{
			cout<<v[1]-v[0];
		}
		else
		{
			cout<<-1;
		}
	}
	else if (k==2)
	{
		if ((v[1]-v[0])%2==0)
		{
			cout<<(v[1]-v[0])/2;
		}
		else
		{
			cout<<(v[1]-v[0]);
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}