#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,n,x,y,d;
	cin>>t;
	while (t--)
	{
		cin>>n>>x>>y>>d;
		if (abs(x-y)%d==0)
		{
			cout<<abs(x-y)/d<<"\n";
		}
		else if (abs(n-y)%d==0)
		{
			if ((y-1)%d==0)
			{
				if ((x-1)%d==0)
				{
					if ((n-x)%d==0)
					{
						cout<<min((abs(y-1)/d)+((x-1)/d),(abs(n-y)/d)+((n-x)/d))<<"\n";
					}
					else
					{
						cout<<min((abs(y-1)/d)+((x-1)/d),(abs(n-y)/d)+((n-x)/d)+1)<<"\n";
					}
				}
				else
				{
					if ((n-x)%d==0)
					{
						cout<<min((abs(y-1)/d)+((x-1)/d)+1,(abs(n-y)/d)+((n-x)/d))<<"\n";
					}
					else
					{
						cout<<min((abs(y-1)/d)+((x-1)/d)+1,(abs(n-y)/d)+((n-x)/d)+1)<<"\n";
					}
				}
			}
			else
			{
				if ((n-x)%d==0)
				{
					cout<<(abs(n-y)/d)+((n-x)/d)<<"\n";
				}
				else
				{
					cout<<(abs(n-y)/d)+((n-x)/d)+1<<"\n";
				}
			}
		}
		else if ((y-1)%d==0)
		{
			if ((x-1)%d==0)
			{
				cout<<(abs(y-1)/d)+((x-1)/d)<<"\n";
			}
			else
			{
				cout<<(abs(y-1)/d)+((x-1)/d)+1<<"\n";
			}
		}
		else
		{
			cout<<"-1\n";
		}
	}
	return 0;
}