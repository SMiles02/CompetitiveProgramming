#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,ans;
	cin>>n;
	int a[n];
	ans=0;
	int weightsDone[150002]={0};
	weightsDone[0]=1;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for (int i=0;i<n;++i)
	{
		if (weightsDone[a[i]-1]==0)
		{
			weightsDone[a[i]-1]=1;
			++ans;
			//cout<<a[i]-1<<"\n";
		}
		else if (weightsDone[a[i]]==0)
		{
			weightsDone[a[i]]=1;
			++ans;
			//cout<<a[i]<<"\n";
		}
		else if (weightsDone[a[i]+1]==0)
		{
			weightsDone[a[i]+1]=1;
			++ans;
			//cout<<a[i]+1<<"\n";
		}
	}
	cout<<ans;
	return 0;
}