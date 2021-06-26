#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll digitsSum(ll val)
{
	ll num,sum=0;
	num = val;
	//cout<<"num is "<<num<<"\n";
	//cout<<"Added ";
    while (num != 0)
    {
    	//cout<<num%10<<" ";
        sum += num % 10;
        num /= 10;
    }
    //cout<<"num: "<<val<<", sum: "<<sum<<"\n";
    return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n,a,b;
	cin>>n;
	if (n>=1000000000000)
	{
		a=999999999999;
		b=n-a;
	}
	else if (n>=100000000000)
	{
		a=99999999999;
		b=n-a;
	}
	else if (n>=10000000000)
	{
		a=9999999999;
		b=n-a;
	}
	else if (n>=1000000000)
	{
		a=999999999;
		b=n-a;
	}
	else if (n>=100000000)
	{
		a=99999999;
		b=n-a;
	}
	else if (n>=10000000)
	{
		a=9999999;
		b=n-a;
	}
	else if (n>=1000000)
	{
		a=999999;
		b=n-a;
	}
	else if (n>=100000)
	{
		a=99999;
		b=n-a;
	}
	else if (n>=10000)
	{
		a=9999;
		b=n-a;
	}
	else if (n>=1000)
	{
		a=999;
		b=n-a;
	}
	else if (n>=100)
	{
		a=99;
		b=n-a;
	}
	else if (n>=10)
	{
		a=9;
		b=n-a;
	}
	else
	{
		a=n;
		b=0;
	}
	cout<<digitsSum(a)+digitsSum(b);
	return 0;
}