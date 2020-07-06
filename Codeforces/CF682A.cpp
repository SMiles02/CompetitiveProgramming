#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll x,y,one1,one2,two1,two2,three1,three2,four1,four2,five1,five2;
	cin>>x>>y;
	one1=(x-(x%5))/5;
	two1=one1;
	three1=one1;
	four1=one1;
	five1=one1;
	if (x%5==1)
	{
		++one1;
	}
	else if (x%5==2)
	{
		++one1;
		++two1;
	}
	else if (x%5==3)
	{
		++one1;
		++two1;
		++three1;
	}
	else if (x%5==4)
	{
		++one1;
		++two1;
		++three1;
		++four1;
	}
	one2=(y-(y%5))/5;
	two2=one2;
	three2=one2;
	four2=one2;
	five2=one2;
	if (y%5==1)
	{
		++one2;
	}
	else if (y%5==2)
	{
		++one2;
		++two2;
	}
	else if (y%5==3)
	{
		++one2;
		++two2;
		++three2;
	}
	else if (y%5==4)
	{
		++one2;
		++two2;
		++three2;
		++four2;
	}
	//cout<<"one1 = "<<one1<<"\n";
	//cout<<"two1 = "<<one1<<"\n";
	//cout<<"three1 = "<<one1<<"\n";
	//cout<<"four1 = "<<one1<<"\n";
	//cout<<"five1 = "<<one1<<"\n";
	//cout<<"one2 = "<<one2<<"\n";
	//cout<<"two2 = "<<one2<<"\n";
	//cout<<"three2 = "<<one2<<"\n";
	//cout<<"four2 = "<<one2<<"\n";
	//cout<<"five2 = "<<one2<<"\n";
	cout<<(one1*four2)+(two1*three2)+(three1*two2)+(four1*one2)+(five1*five2);
	return 0;
}