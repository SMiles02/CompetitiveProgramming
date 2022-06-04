#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k,a,b,c,ab,bc,ac,abc,ans;
	string s;
	a=1000000;b=1000000;c=1000000;ab=1000000;bc=1000000;ac=1000000;abc=1000000;
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>k>>s;
		if (s=="A")
		{
			//cout<<"A found!\n";
			a=min(a,k);
		}
		else if (s=="B")
		{
			//cout<<"B found!\n";
			b=min(b,k);
		}
		else if (s=="C")
		{
			//cout<<"C found!\n";
			c=min(c,k);
		}
		else if (s=="AB"||s=="BA")
		{
			//cout<<"AB found!\n";
			ab=min(ab,k);
		}
		else if (s=="BC"||s=="CB")
		{
			//cout<<"BC found!\n";
			bc=min(bc,k);
		}
		else if (s=="AC"||s=="CA")
		{
			//cout<<"AC found!\n";
			ac=min(ac,k);
		}
		else
		{
			//cout<<"ABC found!\n";
			abc=min(abc,k);
		}
	}
	ans=1000000000;
	if (a!=1000000&&b!=1000000&&c!=1000000)
	{
		ans=a+b+c;
	}
	if (abc!=1000000)
	{
		ans=min(ans,abc);
	}
	if (ab!=1000000&&c!=1000000)
	{
		ans=min(ans,ab+c);
	}
	if (ac!=1000000&&b!=1000000)
	{
		ans=min(ans,ac+b);
	}
	if (bc!=1000000&&a!=1000000)
	{
		ans=min(ans,bc+a);
	}
	if (ab!=1000000&&bc!=1000000)
	{
		ans=min(ans,bc+ab);
	}
	if (bc!=1000000&&ac!=1000000)
	{
		ans=min(ans,bc+ac);
	}
	if (ac!=1000000&&ab!=1000000)
	{
		ans=min(ans,ac+ab);
	}
	if (b!=1000000&&c!=1000000&&ab!=1000000)
	{
		ans=min(ans,b+c+ab);
	}
	if (b!=1000000&&c!=1000000&&ac!=1000000)
	{
		ans=min(ans,b+c+ac);
	}
	if (a!=1000000&&c!=1000000&&bc!=1000000)
	{
		ans=min(ans,a+c+bc);
	}
	if (a!=1000000&&c!=1000000&&ab!=1000000)
	{
		ans=min(ans,a+c+ab);
	}
	if (b!=1000000&&a!=1000000&&ac!=1000000)
	{
		ans=min(ans,b+a+ac);
	}
	if (b!=1000000&&a!=1000000&&bc!=1000000)
	{
		ans=min(ans,b+a+bc);
	}
	if (ans==1000000000)
	{
		//cout<<"A= "<<a<<", B= "<<b<<", C= "<<c<<", AB= "<<ab<<", AC= "<<ac<<", BC= "<<bc<<", ABC= "<<abc<<"\n";
		cout<<-1;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}