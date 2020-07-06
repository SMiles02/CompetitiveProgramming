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
	int n,k;
	cin>>n;
	int a[n][n];
	a[0][0]=1;
	a[n-1][n-1]=0;
	for (int i=0;i<n-2;++i)
	{
		cout<<"? 1 "<<i+1<<" 1 "<<i+3<<endl;
		cin>>k;
		if (k==0)
		{
			a[0][i+2]=1-a[0][i];
		}
		else
		{
			a[0][i+2]=a[0][i];
		}
	}
	for (int i=1;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			cout<<"? "<<i<<" "<<j+1<<" "<<i+1<<" "<<j+1<<endl;
			cin>>k;
			if (k==0)
			{
				a[i][j]=1-a[i-1][j];
			}
			else
			{
				a[i][j]=a[i-1][j];
			}
		}
	}
	cout<<"!"<<endl;
	for (int i=0;i<n;++i)
	{
		for (int j=0;j<n;++j)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}