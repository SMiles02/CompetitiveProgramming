#include <bits/stdc++.h>
#include "scales.h"
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bitset<7> done, l[7], available;

void init(int T) {
    /* ... */
}

void orderCoins() {
    /* ... */
    int x, y, W[] = {0, 0, 0, 0, 0, 0};
    for (int i=1;i<7;++i)
    {
    	done[i]=0;
    	for (int j=1;j<7;++j)
    		l[i][j]=0;
    }
    x=getLightest(1,2,3);
    y=getLightest(4,5,6);
    for (int i=1;i<=3;++i)
    	l[x][i]=1;
    for (int i=4;i<=6;++i)
    	l[y][i]=1;
    for (int i=1;i<=6;++i)
    	if (x!=i&&y!=i)
    	{
    		x=getLightest(i,x,y);
    		W[0]=x;
    		break;
    	}
    for (int N=5;N>0;--N)
    {
    	vector<int> v;
    	for (int i=1;i<7;++i)
    		available[i]=done[i]^1;
    	for (int i=1;i<7;++i)
    		for (int j=1;j<7;++j)
    			if (i!=j&&available[i]&&available[j]&&l[i][j])
    				available[i]=0;
    	for (int i=1;i<7;++i)
    		if (available[i])
    			v.push_back(i);
    	if (sz(v)==1)
    		W[N]=v[0];
    	else if (sz(v)==2)
    	{
    		x=getHeaviest(v[0],v[1],W[0]);
    		W[N]=x;
    	}
    	else if (sz(v)==3)
    	{
    		x=getHeaviest(v[0],v[1],v[2]);
    		W[N]=x;
    	}
    	else if (sz(v)==4)
    	{
    		x=getHeaviest(v[0],v[1],v[2]);
    		for (int i=0;i<3;++i)
    			l[v[i]][x]=1;
    		for (int i=0;i<3;++i)
    			if (v[i]!=x)
    			{
    				W[N]=getHeaviest(v[3],x,v[i]);
    				break;
    			}
    	}
    	else
    	{
    		x=getHeaviest(v[0],v[1],v[2]);
    		for (int i=0;i<3;++i)
    			l[v[i]][x]=1;
    		W[N]=getHeaviest(v[3],v[4],x);
    	}
    	done[W[N]]=1;
    }
    answer(W);
}