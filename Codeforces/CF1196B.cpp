#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q,n,k,x,oddCount;
	cin>>q;
	vector<int> v;
	for (int i=0;i<q;++i)
	{
		cin>>n>>k;
		oddCount=0;
		for (int j=0;j<n;++j)
		{
			cin>>x;
			if (x%2==1)
			{
				++oddCount;
				v.push_back(j+1);
			}
		}
		if (oddCount>=k&&(oddCount-k)%2==0)
		{
			cout<<"YES\n";
			for (int j=1;j<k;++j)
			{
				cout<<v[j-1]<<" ";
			}
			cout<<n<<"\n";
		}
		else
		{
			cout<<"NO\n";
		}
		v.clear();
	}
	return 0;
}