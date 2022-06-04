#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q,n,a,x,total;
	double b;
	bool isTrue;
	cin>>q;
	map<int,int> occurences;
	vector<int> keys;
	while (q--)
	{
		cin>>n;
		x=n*4;
		while (x--)
		{
			cin>>a;
			if (index(a,keys)==-1)
			{
				keys.push_back(a);
				occurences[a]=1;
			}
			else
			{
				++occurences[a];
			}
		}
		b=keys.size();
		sort(keys.begin(), keys.end());
		isTrue=true;
		if (occurences[keys[0]]%2==1)
		{
			isTrue=false;
			//cout<<"test1\n";
		}
		if (occurences[keys[0]]!=occurences[keys[b-1]])
		{
			isTrue=false;
			//cout<<"test2\n";
		}
		if (isTrue==false)
		{
			cout<<"NO\n";
		}
		else
		{
			total=keys[0]*keys[b-1];
			//cout<<total<<"\n";
			for (int i=1;i<(b/2);++i)
			{
				if (occurences[keys[i]]%2==1)
				{
					isTrue=false;
					break;
				}
				if (occurences[keys[i]]!=occurences[keys[b-1-i]])
				{
					isTrue=false;
					break;
				}
				if (keys[i]*keys[b-1-i]!=total)
				{
					isTrue=false;
					break;
				}
			}
			if (isTrue==false)
			{
				cout<<"NO\n";
			}
			else
			{
				cout<<"YES\n";
			}
		}
		occurences.clear();
		keys.clear();
	}
	return 0;
}