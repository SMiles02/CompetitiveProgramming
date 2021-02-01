#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,i,j;
	cin>>n;
	int graph[n][n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin>>graph[i][j];
		}
	}
	cin>>m;
	int initial[m];
	for (i = 0; i < m; i++)
	{
		cin>>initial[i];
	}
	cout<<minInfectionSpread(graph,initial);
	return 0;
}

/**
3
1 1 0
1 1 0
0 0 1
2
0 1
-----------> 0
**/

/**
3
1 0 0
0 1 0
0 0 1
2
0 2
-----------> 0
**/

/**
3
1 1 1
1 1 1
1 1 1
2
1 2
-----------> 1
**/

int minInfectionSpread(int[][] districts, int[] origin)
{
	int minFound,ind,n,m,i,j;
	set<int> infected;
	n = districts.size();
	m = origin.size();
	minFound = n;
	for (i=0;i<m;i++)
	{
		infected.clear();
		for (j=0;j<m;j++)
		{
			if (i!=j)
			{
				if (infected.find(origin[j]) == infected.end())
				{

				}
			}
		}
	}
}
set<int> infect(set<int> infected, int[][] adjacency, int currentIndex)
{
	int n = adjacency.size();
	for (int i = 0; i < n; i++) x for x in input().split(()) cut x with 2
		
	{
		if (adjacency[i][currentIndex] == 1)
		{
			if (infected.find(i) == infected.end())
		}
	}
	return infected;
}