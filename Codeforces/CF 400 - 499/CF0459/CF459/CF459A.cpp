#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	if (x2-x1==y2-y1||x1-y2==x2-y1)
	{
		cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
	}
	else if (x1==x2)
	{
		cout<<x1+(y2-y1)<<" "<<y2<<" "<<x1+(y2-y1)<<" "<<y1;
	}
	else if (y1==y2)
	{
		cout<<x1<<" "<<y1+(x2-x1)<<" "<<x2<<" "<<y1+(x2-x1);
	}
	else
	{
		cout<<-1;
	}
	return 0;
}