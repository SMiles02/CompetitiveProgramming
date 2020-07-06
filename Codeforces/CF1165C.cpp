#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s,t;
	cin>>n;
	cin>>s;
	t="";
	t+=s[0];
	for (int i=1;i<n;++i)
	{
		if (t.length()%2==1)
		{
			if (s[i]!=s[i-1])
			{
				t+=s[i];
			}
		}
		else
		{
			t+=s[i];
		}
	}
	if (t.length()%2==1)
	{
		t.pop_back();
	}
	cout<<s.length()-t.length()<<"\n";
	cout<<t;
	return 0;
}