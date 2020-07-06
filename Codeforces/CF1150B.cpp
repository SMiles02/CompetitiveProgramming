#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}
 
string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	string a[n];
	bool isTrue=true;
	for (int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			if (a[i][j]=='.')
			{
				if (i<n-2&&j>0&&j<n-1)
				{
					if (a[i+1][j]=='.'&&a[i+1][j-1]=='.'&&a[i+1][j+1]=='.'&&a[i+2][j]=='.')
					{
						a[i][j]='#';
						a[i+1][j]='#';
						a[i+2][j]='#';
						a[i+1][j-1]='#';
						a[i+1][j+1]='#';
					}
					else
					{
						isTrue=false;
						break;
					}
				}
				else
				{
					isTrue=false;
					break;
				}
			}
		}
	}
	if (isTrue)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}