#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int b,k,j;
  cin>>b>>k;
  if (b%2==0)
  {
  	for (int i=1;i<k;++i)
  	{
  		cin>>j;
  	}
  	cin>>j;
  	if (j%2==0)
  	{
  		cout<<"even";
  	}
  	else
  	{
  		cout<<"odd";
  	}
  }
  else
  {
  	int ans;
  	ans=0;
  	for (int i=0;i<k;++i)
  	{
  		cin>>j;
  		ans+=j%2;
  	}
  	if (ans%2==0)
  	{
  		cout<<"even";
  	}
  	else
  	{
  		cout<<"odd";
  	}
  }
  return 0;
}