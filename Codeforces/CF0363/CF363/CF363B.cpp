#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k,i,cur,mini,j;
  cin>>n>>k;
  int h[n];
  cur=0;
  for (i=0;i<k;++i)
  {
  	cin>>h[i];
  	cur+=h[i];
  }
  mini=cur;
  j=1;
  for (;i<n;++i)
  {
  	cin>>h[i];
  	cur=cur+h[i]-h[i-k];
  	if (cur<mini)
  	{
  		j=i-k+2;
  		mini=cur;
  	}
  }
  cout<<j;
  return 0;
}