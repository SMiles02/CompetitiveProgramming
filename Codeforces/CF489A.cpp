#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin>>n;
	int a[n];
	int b[n];
	vector<int> ans;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	for (int i=0;i<n-1;++i)
	{
		if (a[i]!=b[i])
		{
			k=a[i];
			a[i]=b[i];
			for (int j=i+1;j<n;++j)
			{
				if (a[j]==a[i])
				{
					ans.push_back(i);
					ans.push_back(j);
					a[j]=k;
					break;
				}
			}
		}
	}
	n=ans.size();
	cout<<n/2<<"\n";
	for (int i=0;i<n;i+=2)
	{
		cout<<ans[i]<<" "<<ans[i+1]<<"\n";
	}
	return 0;
}