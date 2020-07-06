#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,score;
	cin>>n;
	int p[n];
	int q[n];
	for (int i=0;i<n;++i)
	{
		cin>>p[i];
		q[i]=p[i];
	}
	sort(q,q+n);
	score=0;
	for (int i=0;i<n;++i)
	{
		if (q[i]!=p[i])
		{
			++score;
		}
	}
	if (score<=2)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}