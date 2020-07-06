#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,j;
	cin>>n;
	bool done=false;
	for (int i=5;i*i<=n;++i)
	{
		if (n%i==0)
		{
			j=i;
			done=true;
			break;
		}
	}
	if (done==false)
	{
		cout<<-1;
		return 0;
	}
	string s;
	vector<string> v{"a","e","i","o","u"};
	for (int i=0;i<n;++i)
	{
		s.append(v[(i+(i/j))%5]);
	}
	cout<<s;
	return 0;
}