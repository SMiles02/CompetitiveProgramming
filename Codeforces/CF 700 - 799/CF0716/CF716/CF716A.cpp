#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,c,i,current;
  cin>>n>>c;
  int a[n+1];
  a[0]=0;
  current=0;
  for (i=1;i<=n;i++)
  {
  	cin>>a[i];
  	if (a[i]-a[i-1]>c)
  	{
  		current=1;
  	}
  	else
  	{
  		current+=1;
  	}
  }
  cout<<current;
  return 0;
}