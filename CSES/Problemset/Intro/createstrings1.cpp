#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,currentLettersDone=0;
string s,cur="";
vector<string> combos;
map<string,int> m;
map<int,int> doneLetters;

void stringBuilder()
{
	if (currentLettersDone==n)
	{
		if (!m[cur])
		{
			++m[cur];
			combos.push_back(cur);
		}
	}
	else
	{
		for (int i=0;i<n;++i)
		{
			if (!doneLetters[i])
			{
				doneLetters[i]=1;
				cur.push_back(s[i]);
				++currentLettersDone;
				stringBuilder();
				cur.pop_back();
				--currentLettersDone;
				doneLetters[i]=0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>s;
	n=s.length();
	stringBuilder();
	cout<<sz(combos)<<"\n";
	sort(combos.begin(),combos.end());
	n=sz(combos);
	for (int i=0;i<n;++i)
	{
		cout<<combos[i]<<"\n";
	}
	return 0;
}