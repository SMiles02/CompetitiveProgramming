#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q,b,w,adder;
	cin>>q;
	for (int i=0;i<q;++i)
	{
		cin>>b>>w;
		if (b>=w)
		{
			adder=0;
		}
		else
		{
			adder=1;
			int y,z;
			y=b;
			z=w;
			b=z;
			w=y;
		}
		if (3*w+1>=b)
		{
			cout<<"YES\n";
			for (int j=2;j<=(2*w);++j)
			{
				cout<<"2 "<<j+adder<<"\n";
			}
			b-=(w-1);
			if (b>1)
			{
				cout<<"2 "<<1+adder<<"\n";
				cout<<"2 "<<(2*w)+1+adder<<"\n";
				b-=2;
			}
			else if (b>0)
			{
				cout<<"2 "<<1+adder<<"\n";
				--b;
			}
			for (int j=2;b>0&&j<=(2*w);j+=2)
			{
				cout<<"1 "<<j+adder<<"\n";
				--b;
			}
			for (int j=2;b>0&&j<=(2*w);j+=2)
			{
				cout<<"3 "<<j+adder<<"\n";
				--b;
			}

		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}