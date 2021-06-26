#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,differing=0,same=0;
	string s,t,k;
	cin>>n;
	cin>>s;
	cin>>t;
	cout<<"YES\n";
	if (s[0]==s[1])
	{
		++same;
	}
	else
	{
		++differing;
	}
	if (t[0]==t[1])
	{
		++same;
	}
	else
	{
		++differing;
	}
	if (same==2)
	{
		for (int i=0;i<n;++i)
		{
			cout<<"abc";
		}
		return 0;
	}
	if (same==0)
	{
		if (s[0]==t[0])
		{
			if (s[0]=='a')
			{
				for (int i=0;i<n;++i)
				{
					cout<<"bc";
				}
			}
			if (s[0]=='b')
			{
				for (int i=0;i<n;++i)
				{
					cout<<"ac";
				}
			}
			if (s[0]=='c')
			{
				for (int i=0;i<n;++i)
				{
					cout<<"ab";
				}
			}
			for (int i=0;i<n;++i)
			{
				cout<<s[0];
			}
			return 0;
		}
		if (s[1]==t[1])
		{
			for (int i=0;i<n;++i)
			{
				cout<<s[1];
			}
			if (s[1]=='a')
			{
				for (int i=0;i<n;++i)
				{
					cout<<"bc";
				}
			}
			if (s[1]=='b')
			{
				for (int i=0;i<n;++i)
				{
					cout<<"ac";
				}
			}
			if (s[1]=='c')
			{
				for (int i=0;i<n;++i)
				{
					cout<<"ab";
				}
			}
			return 0;
		}
		if (s[0]==t[1]&&s[1]==t[0])
		{
			for (int i=0;i<n;++i)
			{
				cout<<s[0];
			}
			if ('c'==s[0]||'c'==t[0])
			{
				if ('a'==s[0]||'a'==t[0])
				{
					for (int i=0;i<n;++i)
					{
						cout<<"b";
					}
				}
				else
				{
					for (int i=0;i<n;++i)
					{
						cout<<"a";
					}
				}
			}
			else
			{
				for (int i=0;i<n;++i)
				{
					cout<<"c";
				}
			}
			for (int i=0;i<n;++i)
			{
				cout<<s[1];
			}
			return 0;
		}
		if (s[1]==t[0])
		{
			for (int i=0;i<n;++i)
			{
				cout<<t[1];
			}
			for (int i=0;i<n;++i)
			{
				cout<<t[0];
			}
			for (int i=0;i<n;++i)
			{
				cout<<s[0];
			}
			return 0;
		}
		if (s[0]==t[1])
		{
			for (int i=0;i<n;++i)
			{
				cout<<s[1];
			}
			for (int i=0;i<n;++i)
			{
				cout<<s[0];
			}
			for (int i=0;i<n;++i)
			{
				cout<<t[0];
			}
		}
		return 0;
	}
	if (t[0]==t[1])
	{
		k=t;
		t=s;
		s=k;
	}
	if (s[0]==t[0])
	{
		k=s[0];
		if (t[0]=='a'||t[1]=='a')
		{
			if (t[0]=='b'||t[1]=='b')
			{
				k+="c";
			}
			else
			{
				k+="b";
			}
		}
		else
		{
			k+="a";
		}
		k+=t[1];
		for (int i=0;i<n;++i)
		{
			cout<<k;
		}
		return 0;
	}
	if (s[0]==t[1])
	{
		k=t[0];
		if (t[0]=='a'||t[1]=='a')
		{
			if (t[0]=='b'||t[1]=='b')
			{
				k+="c";
			}
			else
			{
				k+="b";
			}
		}
		else
		{
			k+="a";
		}
		k+=t[1];
		for (int i=0;i<n;++i)
		{
			cout<<k;
		}
		return 0;
	}
	k=s[0];
	k+=t[1];
	k+=t[0];
	for (int i=0;i<n;++i)
	{
		cout<<k;
	}
	return 0;
}