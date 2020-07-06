#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,currentSPosition=0;
	ll fullLoops=0;
	string s,t,alpha="abcdefghijklmnopqrstuvwxyz";
	cin>>s;
	cin>>t;
	n=s.length();
	m=t.length();
	map<int,map<char,int>> future;
	map<char,int> nextOccurence;
	for (int i=0;i<26;++i)
	{
		nextOccurence[alpha[i]]=-1;
	}
	future[n]=nextOccurence;
	for (int i=n;i>0;--i)
	{
		nextOccurence[s[i-1]]=i;
		future[i-1]=nextOccurence;
	}
	for (int i=0;i<m;++i)
	{
		if (future[currentSPosition][t[i]]==-1)
		{
			//cout<<"NEWLOOP at i="<<i<<"\n";
			++fullLoops;
			if (future[0][t[i]]==-1)
			{
				cout<<-1;
				return 0;
			}
			currentSPosition=future[0][t[i]];
		}
		else
		{
			currentSPosition=future[currentSPosition][t[i]];
		}
		//cout<<"currentSPosition = "<<currentSPosition<<"\n";
	}
	//cout<<fullLoops<<" "<<currentSPosition<<"\n";
	fullLoops*=n;
	fullLoops+=currentSPosition;
	cout<<fullLoops;
	return 0;
}