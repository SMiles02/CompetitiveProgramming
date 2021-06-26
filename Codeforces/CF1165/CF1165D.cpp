#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t,n,k,x,i;
	bool right;
	vector<ll> input;
	vector<ll> found;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (i=0;i<n;++i)
		{
			cin>>k;
			input.push_back(k);
		}
		sort(input.begin(),input.end());
		x=input[0]*input[n-1];
		//cout<<"x: "<<x<<"\n";
		for (i=2;i*i<x;++i)
		{
			if (x%i==0)
			{
				found.push_back(i);
				found.push_back(x/i);
				//cout<<"Added "<<i<<"\n";
				//cout<<"Added "<<x/i<<"\n";
			}
		}
		if (i*i==x)
		{
			found.push_back(i);
		}
		if (found.size()==n)
		{
			sort(found.begin(),found.end());
			right=true;
			for (i=0;i<n;++i)
			{
				//cout<<"i: "<<i<<", "<<found[i]<<" "<<input[i]<<"\n";
				if (found[i]!=input[i])
				{
					right=false;
					break;
				}
			}
			if (right)
			{
				cout<<x<<"\n";
			}
			else
			{
				cout<<"-1\n";
			}
		}
		else
		{
			cout<<"-1\n";
		}
		input.clear();
		found.clear();
		//cout<<"\n";
	}
	return 0;
}