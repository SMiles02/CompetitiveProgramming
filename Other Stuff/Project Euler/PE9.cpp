#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	float i;
	for (int a=1;a<1000;++a)
	{
		for (int b=1;b<1000;++b)
		{
			i=a*a;
			i+=b*b;
			i=sqrt(i);
			if (1000==a+b+i)
			{
				cout<<a*b*i<<"\n";
				cout<<a<<" "<<b<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}