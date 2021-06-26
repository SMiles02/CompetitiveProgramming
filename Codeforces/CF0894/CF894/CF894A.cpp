#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,qTotal,ans,k,before;
  string s;
  cin>>s;
  n=s.length();
  qTotal=0;
  map<int,int> scores;
  vector<int> aPositions;
  for (int i=0;i<n;++i)
  {
  	if (s[i]=='Q')
  	{
  		++qTotal;
  	}
  	else if (s[i]=='A')
  	{
  		aPositions.push_back(i);
  		scores[i]=qTotal;
  	}
  }
  ans=0;
  k=aPositions.size();
  for (int i=0;i<k;++i)
  {
  	before=scores[aPositions[i]];
  	ans+=before*(qTotal-before);
  }
  cout<<ans;
  return 0;
}