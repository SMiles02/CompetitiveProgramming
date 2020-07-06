#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,i,big,big2;
  cin>>n;
  int a[n];
  big=0;
  big2=0;
  for (i=0;i<n;i++)
  {
  	cin>>a[i];
  	if (a[i] >= big)
  	{
  		big2=big;
  		big=a[i];
  	}
  	else if (a[i]>big2)
  	{
  		big2=a[i];
  	}
  }
  //cout<<big<<" "<<big2<<"\n";
  for (i=0;i<n;i++)
  {
  	if (a[i]==big)
  	{
  		cout<<big2<<"\n";
  	}
  	else
  	{
  		cout<<big<<"\n";
  	}
  }
  return 0;
}