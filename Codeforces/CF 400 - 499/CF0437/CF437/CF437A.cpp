#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s1,s2,s3,s4;
	int a[4];
	cin>>s1;
	cin>>s2;
	cin>>s3;
	cin>>s4;
	int n1,n2,n3;
	n1=s1.length()-2;
	n2=s2.length()-2;
	n3=s3.length()-2;
	a[0]=s1.length()-2;
	a[1]=s2.length()-2;
	a[2]=s3.length()-2;
	a[3]=s4.length()-2;
	sort(a,a+4);
	if (a[0]*2<=a[1]&&a[2]*2<=a[3])
	{
		cout<<'C';
	}
	else if (a[0]*2<=a[1])
	{
		if (n1==a[0])
		{
			cout<<'A';
		}
		else if (n2==a[0])
		{
			cout<<'B';
		}
		else if (n3==a[0])
		{
			cout<<'C';
		}
		else
		{
			cout<<'D';
		}
	}
	else if (a[2]*2<=a[3])
	{
		if (n1==a[3])
		{
			cout<<'A';
		}
		else if (n2==a[3])
		{
			cout<<'B';
		}
		else if (n3==a[3])
		{
			cout<<'C';
		}
		else
		{
			cout<<'D';
		}
	}
	else
	{
		cout<<'C';
	}
	return 0;
}