#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,sum,totalDifference;
	cin>>n>>k;
	int a[n];
	sum=0;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if (sum%n==0)
	{
		totalDifference=0;
		for (int j=0;j<n;++j)
		{
			totalDifference+=min(a[j]%sum,sum-(a[j]%sum));
		}
		totalDifference/=2;
		if (totalDifference<=k)
		{
			cout<<sum;
			return 0;
		}
		sum/=n;
		vector<int> divisors;
		for (int i=1;i*i<sum;++i)
		{
			if (sum%i==0)
			{
				divisors.push_back(i);
				divisors.push_back(sum/i);
			}
		}
		int sqy=sqrt(sum);
		if (sqrt(sum)==sqy)
		{
			divisors.push_back(sqy);
		}
		sort(divisors.rbegin(), divisors.rend());
		int f=divisors.size();
		for (int i=0;i<f;++i)
		{
			totalDifference=0;
			for (int j=0;j<n;++j)
			{
				totalDifference+=min(a[j]%divisors[i],divisors[i]-(a[j]%divisors[i]));
			}
			totalDifference/=2;
			if (totalDifference<=k)
			{
				cout<<divisors[i];
				return 0;
			}
		}
	}
	else
	{
		cout<<1;
	}
	return 0;
}