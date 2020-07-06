#include <bits/stdc++.h>
#define ll long long
using namespace std;

int maxi(int a[],int n)
{
	int maxt=0;
	for (int i=0;i<n;++i)
	{
		//cout<<a[i]<<" ";
		maxt=max(maxt,a[i]);
	}
	//cout<<"\n";
	return maxt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,q,a,b,biggest,cur;
	cin>>n>>m>>q;
	int matrix[n][m];
	int answers[n];
	for (int i=0;i<n;++i)
	{
		cur=0;biggest=0;
		for (int j=0;j<m;++j)
		{
			cin>>matrix[i][j];
			if (matrix[i][j])
			{
				++cur;
			}
			else
			{
				biggest=max(biggest,cur);
				cur=0;
			}
		}
		biggest=max(biggest,cur);
		answers[i]=biggest;
	}
	//cout<<maxi(answers,n)<<"\n";
	for (int i=0;i<q;++i)
	{
		cin>>a>>b;
		--a;
		--b;
		matrix[a][b]=1-matrix[a][b];
		cur=0;biggest=0;
		for (int j=0;j<m;++j)
		{
			if (matrix[a][j])
			{
				++cur;
			}
			else
			{
				biggest=max(biggest,cur);
				cur=0;
			}
		}
		biggest=max(biggest,cur);
		answers[a]=biggest;
		cout<<maxi(answers,n)<<"\n";
	}
	return 0;
}