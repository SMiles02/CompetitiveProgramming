#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	string t;
	cin>>n;
	cin>>s;
	cin>>t;
	char z;
	bool found;
	vector<int> ansL;
	for (int i=0;i<n;++i)
	{
		if (s[i]!=t[i])
		{
			found=false;
			for (int j=i+1;j<n;++j)
			{
				if (s[j]==t[i])
				{
					found=true;
					for (int k=j;k>i;--k)
					{
						ansL.push_back(k-1);
						z=s[k-1];
						s[k-1]=s[k];
						s[k]=z;
					}
					break;
				}
			}
			if (found==false)
			{
				cout<<-1;
				return 0;
			}
		}
	}
	n=ansL.size();
	cout<<n<<"\n";
	for (int i=0;i<n;++i)
	{
		cout<<ansL[i]+1<<" ";
	}
	return 0;
}