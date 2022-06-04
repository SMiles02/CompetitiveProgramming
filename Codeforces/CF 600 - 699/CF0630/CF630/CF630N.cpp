#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	float a,b,c,x1,x2;
	cin>>a>>b>>c;
	x1=(-b+sqrt((b*b)-4*a*c))/(2*a);
	x2=(-b-sqrt((b*b)-4*a*c))/(2*a);
	cout<<setprecision(15)<<max(x1,x2)<<"\n";
	cout<<setprecision(15)<<min(x1,x2);
	return 0;
}