#include "vision.h"
#include <bits/stdc++.h>
using namespace std;

void construct_network(int H, int W, int K)
{
	vector<int> v;
	for (int i=0;i<H;++i)
		for (int j=0;j<W;++j)
		{
			vector<int> w;
			for (int k=j+1;k<W;++k)
				if (k-j==K)
					w.push_back(i*W+k);
			for (int k=i+1;k<H&&k-i<=K;++k)
			{
				if (k-i==K)
					w.push_back(k*W+j);
				else
				{
					if (0<=j-K+k-i)
						w.push_back(k*W+j-K+k-i);
					if (j+K-k+i<W)
						w.push_back(k*W+j+K-k+i);
				}
			}
			if (!w.empty())
				v.push_back(add_and({i*W+j,add_or(w)}));
		}
	add_or(v);
}