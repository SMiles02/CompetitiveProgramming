#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i=0;i<401;++i)
	{
		cout<<i<<" "<<13*i+5<<"\n";
	}
	cout<<"\n";
	int num=1;
	for (int i=1;i<=9;++i)
	{
		num*=10;
		cout<<i<<": "<<num%13<<"\n";
	}
	return 0;
}