#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include "dungeons.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e5+7;
int n;
vector<int> s, w, l;
ll t[N], p[N];

void init(int d, std::vector<int> S, std::vector<int> P, std::vector<int> W, std::vector<int> L) {
	n = d;
	s = S;
	w = W;
	l = L;
	for (int i=0;i<n;++i)
		t[i] = s[i];
	for (int i=0;i<n;++i)
		p[i] = P[i];
	for (int j=0;j<200;++j)
	{
		for (int i=0;i<n;++i)
		{
			if (w[i] != n && s[i] + t[i] >= s[w[i]])
			{
				t[i] += t[w[i]];
				w[i] = w[w[i]];
			}
			if (l[i] != n && s[i] + p[i] <= s[l[i]])
			{
				p[i] += p[l[i]];
				l[i] = l[l[i]];
			}
			if (l[i] != n && p[i] + 1 >= s[l[i]])
			{
				p[i] += t[l[i]];
				l[i] = w[l[i]];
			}
		}
		for (int i=n-1;i>=0;--i)
		{
			if (w[i] != n && s[i] + t[i] >= s[w[i]])
			{
				t[i] += t[w[i]];
				w[i] = w[w[i]];
			}
			if (l[i] != n && s[i] + p[i] <= s[l[i]])
			{
				p[i] += p[l[i]];
				l[i] = l[l[i]];
			}
			if (l[i] != n && p[i] + 1 >= s[l[i]])
			{
				p[i] += t[l[i]];
				l[i] = w[l[i]];
			}
		}
	}
	return;
}

long long simulate(int x, int y) {
	ll z = y;
	while (x != n)
	{
		if (z >= s[x])
		{
			z += t[x];
			x = w[x];
		}
		else
		{
			z += p[x];
			x = l[x];
		}
	}
	return z;
}

