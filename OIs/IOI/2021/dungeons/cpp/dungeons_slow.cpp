#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include "dungeons.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 4e5+7;
int n;
vector<int> s, p, w, l;

void init(int d, std::vector<int> S, std::vector<int> P, std::vector<int> W, std::vector<int> L) {
	n = d;
	s = S;
	p = P;
	w = W;
	l = L;
	return;
}

long long simulate(int x, int y) {
	ll z = y;
	while (x != n)
	{
		if (z >= s[x])
		{
			z += s[x];
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

