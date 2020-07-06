#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

vector<vector<int>> permutationsGenerator(vector<int> numbers, vector<int> soFar, vector<vector<int>> possibilities, int currentLength, int n)
{
	if (currentLength==n)
	{
		possibilities.push_back(soFar);
		return possibilities;
	}
	else
	{
		vector<int> v;
		for (int i=0;i<(n-currentLength);++i)
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
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> v;
	vector<int> p;
	for (int i=1;i<=n;++i)
	{
		v.push_back(i);
	}
	vector<vector<int>> possibilities;
	possibilities=permutationsGenerator(v,p,possibilities,0,n);
	int a[m][2];
	for (int i=0;i<m;++i)
	{
		cin>>a[i][0]>>a[i][1];
	}
	if (n==1)
	{
		cout<<0;
	}
	if (n==2)
	{
		int reverseOrNot[4][2]={{0,0},{0,1},{1,0},{1,1}};
	}
	if (n==3)
	{
		int reverseOrNot[8][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
	}
	int d=reverseOrNot.size();
	int score;
	bool isTrue;
	for (int i=0;i<possibilities.size();++i)
	{
		for (int j=0;j<reverseOrNot;++j)
		{
			isTrue=true;
			score=0;
			for (int k=0;k<m;++k)
			{
				if ()
			}
		}
	}
	return 0;
}