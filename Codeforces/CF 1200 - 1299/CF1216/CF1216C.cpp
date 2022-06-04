#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x1,x2,x3,x4,x5,x6;
	int y1,y2,y3,y4,y5,y6;
	ll ans=0,area,cur;
	int l1,r1,u1,d1;
	int l2,r2,u2,d2;
	int l3,r3,u3,d3;
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	cin>>x4>>y4;
	cin>>x5>>y5;
	cin>>x6>>y6;
	area=(x2-x1);
	area*=(y2-y1);
	l1=max(x1,x3);
	r1=min(x2,x4);
	d1=max(y1,y3);
	u1=min(y2,y4);
	l2=max(x1,x5);
	r2=min(x2,x6);
	d2=max(y1,y5);
	u2=min(y2,y6);
	l3=max(l1,l2);
	r3=min(r1,r2);
	d3=max(d1,d2);
	u3=min(u1,u2);
	if (l1<r1&&d1<u1)
	{
		ans=(r1-l1);
		ans*=(u1-d1);
		if (l2<r2&&d2<u2)
		{
			cur=(r2-l2);
			cur*=(u2-d2);
			ans+=cur;
			if (l3<r3&&d3<u3)
			{
				cur=(r3-l3);
				cur*=(u3-d3);
				ans-=cur;
			}
		}
	}
	else if  (l2<r2&&d2<u2)
	{
		ans=(r2-l2);
		ans*=(u2-d2);
	}
	//cout<<area<<"\n";
	//cout<<ans<<"\n";
	if (ans==area)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES";
	}
	return 0;
}