#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k,acceptedLength,f;
	bool isTrue=true;
	cin>>n>>m;
	string s[n];
	string password = "";
	map<int,int> toDelete;
	vector<int> deleters;
	for (int i=0;i<n;++i)
	{
		cin>>s[i];
	}
	cin>>k;
	--k;
	++toDelete[k];
	deleters.push_back(k);
	acceptedLength=s[k].length();
	for (int i=1;i<m;++i)
	{
		cin>>k;
		--k;
		++toDelete[k];
		deleters.push_back(k);
		f=s[k].length();
		if (acceptedLength!=f)
		{
			isTrue=false;
		}
	}
	if (!isTrue)
	{
		cout<<"No";
		return 0;
	}
	for (int i=0;i<acceptedLength;++i)
	{
		isTrue=true;
		//cout<<"s[deleters[0]]["<<i<<"] = "<<s[deleters[0]][i]<<"\n";
		for (int j=1;j<m;++j)
		{
			if (s[deleters[0]][i]!=s[deleters[j]][i])
			{
				isTrue=false;
			}
		}
		if (isTrue)
		{
			password+=s[deleters[0]][i];
		}
		else
		{
			password+='?';
		}
	}
	for (int i=0;i<n;++i)
	{
		if (toDelete[i]==0)
		{
			f=s[i].length();
			if (acceptedLength==f)
			{
				isTrue=true;
				for (int j=0;j<acceptedLength;++j)
				{
					if (password[j]!='?'&&password[j]!=s[i][j])
					{
						isTrue=false;
						break;
					}
				}
				if (isTrue)
				{
					cout<<"No";
					return 0;
				}
			}
		}
	}
	cout<<"Yes\n"<<password;
	return 0;
}