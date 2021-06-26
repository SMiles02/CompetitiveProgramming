#include "dungeons.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e5+7, LG = 25;
int n;
ll up[4][LG][N];
vector<int> s, p, w, l;

void init(int d, std::vector<int> S, std::vector<int> P, std::vector<int> W, std::vector<int> L) {
	n = d;
	s = S;
	p = P;
	w = W;
	l = L;
	for (int i=0;i<n;++i)
		up[0][0][i] = l[i];
	up[0][0][n] = n;
	for (int i=1;i<LG;++i)
	{
		for (int j=0;j<n;++j)
			up[0][i][j] = up[0][i-1][up[0][i-1][j]];
		up[0][i][n] = n;
	}
	for (int i=0;i<n;++i)
		up[1][0][i] = w[i];
	up[1][0][n] = n;
	for (int i=1;i<LG;++i)
	{
		for (int j=0;j<n;++j)
			up[1][i][j] = up[1][i-1][up[1][i-1][j]];
		up[1][i][n] = n;
	}
	for (int i=0;i<n;++i)
		up[2][0][i] = p[i];
	up[2][0][n] = 0;
	for (int i=1;i<LG;++i)
	{
		for (int j=0;j<n;++j)
			up[2][i][j] = up[2][i-1][j] + up[2][i-1][up[0][i-1][j]];
		up[2][i][n] = 0;
	}
	//for (int i=0;i<LG;++i)
	//{
		//cout << "! ";
		//for (int j=0;j<n;++j)
			//cout << up[0][i][j] << " ";
		//cout << endl;
	//}
	for (int i=0;i<n;++i)
		up[3][0][i] = s[i];
	up[3][0][n] = 0;
	for (int i=1;i<LG;++i)
	{
		for (int j=0;j<n;++j)
			up[3][i][j] = up[3][i-1][j] + up[3][i-1][up[1][i-1][j]];
		up[3][i][n] = 0;
	}
	return;
}

long long simulate(int x, int y) {
	ll z = y;
	for (int i=LG-1;i>=0;--i)
		if (z + up[2][i][x] < s[0] && up[0][i][x] < n)
		{
			//cout << "!! " << x << " " << i << " " << z << endl;
			//cout << "!! " << up[0][i][x] << endl;
			z += up[2][i][x];
			x = up[0][i][x];
		}
	if (z < s[0])
	{
		z += up[2][0][x];
		x = up[0][0][x];
	}
	//cout << "! " << x << " " << z << endl;
	for (int i=LG-1;i>=0;--i)
		if (up[1][i][x] < n)
		{
			// cout << "!! " << x << " " << i << " " << z << endl;
			// cout << "!! " << up[1][i][x] << endl;
			z += (1LL << i) * s[0];
			// cout << "!! " << x << " " << z << endl;
			x = up[1][i][x];
		}
	// cout << "! " << x << " " << z << endl;
	if (x < n)
	{
		z += s[0];
		x = up[1][0][x];
	}
	return z;
}

/**

3 1
10 10 10
3 2 1
1 2 3
1 0 1
2 1

**/
