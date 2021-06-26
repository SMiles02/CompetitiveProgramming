#include "dna.h"
#include <bits/stdc++.h>
using namespace std;

int p[6][1<<17], r[6];

void init(std::string s, std::string t) {
	int n = s.size();
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<6;++j)
			p[j][i+1] = p[j][i];
		if (s[i] == 'A')
		{
			if (t[i] == 'T')
				++p[0][i+1];
			if (t[i] == 'C')
				++p[1][i+1];
		}
		if (s[i] == 'T')
		{
			if (t[i] == 'A')
				++p[2][i+1];
			if (t[i] == 'C')
				++p[3][i+1];
		}
		if (s[i] == 'C')
		{
			if (t[i] == 'A')
				++p[4][i+1];
			if (t[i] == 'T')
				++p[5][i+1];
		}
	}
}

int pair_up(int x, int y)
{
	int z = min(r[x], r[y]);
	r[x] -= z;
	r[y] -= z;
	return z;
}

int get_distance(int x, int y)
{
	int ans = 0;
	++x;
	++y;
	for (int i=0;i<6;++i)
		r[i] = p[i][y] - p[i][x-1];
	if (r[0] + r[1] != r[2] + r[4] || r[2] + r[3] != r[0] + r[5] || r[4] + r[5] != r[1] + r[3])
		return -1;
	ans += pair_up(0, 2);
	ans += pair_up(1, 4);
	ans += pair_up(3, 5);
	return ans + ((r[0] + r[1] + r[2] + r[3] + r[4] + r[5])/3)*2;
}