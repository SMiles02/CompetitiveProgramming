#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> permutationsGenerator(vector<int> numbers, vector<int> soFar, vector<vector<int>> possibilities, int currentLength)
{
	if (currentLength==6)
	{
		possibilities.push_back(soFar);
		return possibilities;
	}
	else
	{
		vector<int> v;
		for (int i=0;i<(6-currentLength);++i)
		{
			v=numbers;
			soFar.push_back(numbers[i]);
			numbers.erase(numbers.begin()+i);
			possibilities=permutationsGenerator(numbers,soFar,possibilities,currentLength+1);
			soFar.erase(soFar.begin()+currentLength);
			numbers=v;
		}
		return possibilities;
	}
}

int main()
{
	vector<int> v;
	vector<int> p;
	v.push_back(4);
	v.push_back(8);
	v.push_back(15);
	v.push_back(16);
	v.push_back(23);
	v.push_back(42);
	vector<vector<int>> possibilities;
	possibilities=permutationsGenerator(v,p,possibilities,0);
	int a,b,c,d;
	cout<<"? 1 2"<<endl;
	cin>>a;
	cout<<"? 2 3"<<endl;
	cin>>b;
	cout<<"? 3 4"<<endl;
	cin>>c;
	cout<<"? 4 5"<<endl;
	cin>>d;
	for (int i=0;i<720;++i)
	{
		if (a==possibilities[i][0]*possibilities[i][1])
		{
			if (b==possibilities[i][2]*possibilities[i][1])
			{
				if (c==possibilities[i][2]*possibilities[i][3])
				{
					if (d==possibilities[i][3]*possibilities[i][4])
					{
						cout<<"! ";
						for (int j=0;j<6;++j)
						{
							cout<<possibilities[i][j]<<" ";
						}
						return 0;
					}
				}
			}
		}
	}
	ios_base::sync_with_stdio(0); cin.tie(0);
	return 0;
}