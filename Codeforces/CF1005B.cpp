#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s,t;
  int n,m,i,k;
  cin>>s;
  cin>>t;
  n=s.length();
  m=t.length();
  k=min(n,m);
  for (i=1;i<=k;i++)
  {
  	if (s[n-i] != t[m-i])
  	{
  		break;
  	}
  }
  cout<<n+m-(2*(i-1));
  return 0;
}