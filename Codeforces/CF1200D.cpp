#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,cur,ans,perf,f;
	cin>>n>>k;
	string s;
	int indexOfFirst[n];
	bool done,secondDone;
	for (int i=0;i<n;++i)
	{
		cin>>s;
		done=false;
		for (int j=0;j<n;++j)
		{
			if (s[j]=='B')
			{
				done=true;
				secondDone=false;
				for (int l=j+k;l<n;++l)
				{
					if (s[l]=='B')
					{
						indexOfFirst[i]=-1;
						secondDone=true;
						break;
					}
				}
				if (secondDone==false)
				{
					indexOfFirst[i]=j;
				}
				break;
			}
		}
		if (done==false)
		{
			indexOfFirst[i]=100000;
		}
	}
	ans=0;
	vector<int> v;
	for (int i=0;i<n-k;++i)
	{
		perf=0;
		for (int j=i;j<i+k;++j)
		{
			if (indexOfFirst[j]==100000)
			{
				++perf;
			}
			else if (indexOfFirst[j]>-1)
			{
				v.push_back(indexOfFirst[j]);
			}
		}
		sort(v.begin(),v.end());
		f=v.size();
		for (int j=0;j<f;++j)
		{
			cur=1;
			for (int l=j+1;l<f;++l)
			{
				if (v[l]-v[j]<k)
				{
					++cur;
				}
			}
			ans=max(ans,cur+perf);
		}
	}
	cout<<ans;
	return 0;
}