#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll q,a,b,c;
	cin>>q;
	for (int i=0;i<q;++i)
	{
		cin>>a>>b>>c;
		if (a+b+c%2==1)
		{
			--a;
		}
		cout<<((a+b+c)/2)<<"\n";
	}
	return 0;
}