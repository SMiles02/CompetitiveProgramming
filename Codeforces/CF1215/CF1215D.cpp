#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,firstH=0,secondH=0,questionsA=0,questionsB=0;
	cin>>n;
	string s;
	cin>>s;
	for (int i=0;i<(n/2);++i)
	{
		if (s[i]=='?')
		{
			++questionsA;
		}
		else
		{
			firstH+=(s[i]-'0');
		}
	}
	for (int i=(n/2);i<n;++i)
	{
		if (s[i]=='?')
		{
			++questionsB;
		}
		else
		{
			secondH+=(s[i]-'0');
		}
	}
	if (questionsA==questionsB)
	{
		if (firstH==secondH)
		{
			cout<<"Bicarp";
		}
		else
		{
			cout<<"Monocarp";
		}
	}
	else
	{
		if (questionsB>questionsA)
		{
			swap(questionsA,questionsB);
			swap(firstH,secondH);
		}
		questionsA-=questionsB;
		questionsB=0;
		if (firstH>=secondH)
		{
			cout<<"Monocarp";
		}
		else
		{
			if (questionsA%2)
			{
				
			}
			else
			{
				if (9*(questionsA/2)+firstH==secondH)
				{
					cout<<"Bicarp";
				}
				else
				{
					cout<<"Monocarp";
				}
			}
		}
	}
	return 0;
}